#!/usr/bin/env python3
import time
import numpy as np
import cv2
import cvzone
from cvzone.ColorModule import ColorFinder

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge

# Import custom message types
from process_msgs.msg import Cube, CubeArray

class CubeTracker(Node):
    """Cube tracker node: detects HSV values the colored cubes and publishes a CubeArray."""

    def __init__(self):
        super().__init__('cube_tracker')

        # Subscribers & Publishers
        self.sub = self.create_subscription(Image,
                                           '/camera/image_raw',
                                           self.image_callback,
                                           10)
        # Single publisher for all cube detections
        self.pub_cubes = self.create_publisher(CubeArray,
                                               '/cubes/detections',
                                               10)

        # CV setup
        self.bridge = CvBridge()
        self.color_finder = ColorFinder(False)


        #self.color_ranges = { # Define HSV color ranges for different cubes (Lights on)
        #    'red':    {'hmin': 0,  'smin': 57,  'vmin': 243, 'hmax': 12,  'smax': 135, 'vmax': 255},
        #    'blue':   {'hmin': 93, 'smin': 184, 'vmin': 200, 'hmax': 108, 'smax': 222, 'vmax': 255},
        #    'yellow': {'hmin': 9, 'smin': 103, 'vmin': 101, 'hmax': 28, 'smax': 176, 'vmax': 239},  # enable if needed
        #    'green':  {'hmin': 31, 'smin': 29,  'vmin': 139, 'hmax': 78,  'smax': 109, 'vmax': 244},
        #}

        #self.color_ranges = { # Define HSV color ranges for different cubes (Lights off)
        #    'red':   {'hmin': 134, 'smin': 131, 'vmin': 0, 'hmax': 179, 'smax': 186, 'vmax': 255},
        #    'blue':  {'hmin': 102, 'smin': 164, 'vmin': 124, 'hmax': 165, 'smax': 244, 'vmax': 255},
        #    'yellow': {'hmin': 9, 'smin': 103, 'vmin': 101, 'hmax': 28, 'smax': 176, 'vmax': 239},
        #    'green': {'hmin': 48, 'smin': 64, 'vmin': 53, 'hmax': 91, 'smax': 117, 'vmax': 107},
        #}

        self.color_ranges = { # Define HSV color ranges for different cubes (Semi controlled lighting)
            'red':   {'hmin': 35, 'smin': 4, 'vmin': 255, 'hmax': 179, 'smax': 241, 'vmax': 255},
            'blue':  {'hmin': 100, 'smin': 102, 'vmin': 90, 'hmax': 114, 'smax': 224, 'vmax': 255},
            'yellow': {'hmin': 14, 'smin': 55, 'vmin': 164, 'hmax': 42, 'smax': 194, 'vmax': 255},
            'green': {'hmin': 37, 'smin': 82, 'vmin': 86, 'hmax': 82, 'smax': 157, 'vmax': 170},
        }

        # Logging
        self.last_log = {c: 0.0 for c in self.color_ranges}
        self.log_interval = 2.5

        self.get_logger().info('CubeTracker started, publishing CubeArray')

    def image_callback(self, msg: Image):
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        detections = []

        for color, hsv in self.color_ranges.items():
            _, mask = self.color_finder.update(img, hsv)
            img_out, contours = cvzone.findContours(img, mask)

            if not contours:
                continue

            info = contours[0]  # largest contour
            cx, cy = info['center']
            area = info['area']
            cnt = info['cnt']

            # Bounding box and angle
            rect = cv2.minAreaRect(cnt)
            (cx_box, cy_box), (w, h), angle = rect

            # Draw for debug
            box = cv2.boxPoints(rect).astype(int)
            color_bgr = {'red': (0,0,255), 'blue': (255,0,0), 'green': (0,255,0), 'yellow': (0,255,255)}
            cv2.drawContours(img, [box], 0, color_bgr[color], 2)
            cv2.putText(img, color.upper(), (int(cx_box), int(cy_box)-10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, color_bgr[color], 2)

            # Log periodically
            now = time.time()
            if now - self.last_log[color] >= self.log_interval:
                self.get_logger().info(f"{color.upper()} at ({cx:.0f},{cy:.0f}), area={area:.0f}, angle={angle:.1f}")
                self.last_log[color] = now

            # Build Cube message
            cube = Cube()
            cube.color = color
            cube.position = Point(x=float(cx), y=float(cy), z=float(area))
            cube.angle = float(angle)
            detections.append(cube)

        # Publish all detections
        arr = CubeArray()
        arr.cubes = detections
        self.pub_cubes.publish(arr)

        # Show debug window
        cv2.imshow('Cube Tracking', img)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = CubeTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
