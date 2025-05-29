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
from process_msgs.msg import Cube, CubeArray

class CubeTracker(Node):
    """Cube tracker node: detects HSV values the colored cubes and publishes a CubeArray."""

    def __init__(self):
        super().__init__('cube_tracker')

        # Subscribers & Publishers
        self.sub = self.create_subscription(Image,'/camera/image_raw',self.image_callback,10)
        # Single publisher for all cube detections
        self.pub_cubes = self.create_publisher(CubeArray,'/cubes/detections',10)

        # CV setup
        self.bridge = CvBridge()
        self.color_finder = ColorFinder(False)
        
        # Startup variables
        self.first_image_processed = False
        self.start_time = time.time()

        self.last_processed_time = 0
        self.process_interval = 1/40  # cube_tracker runtime delay in seconds
        self.startup_delay = 2.0  # Delay before starting image processing

        self.hsv_profiles = [ # Defines different HSV profiles for cube detection. Each profile made for different lighting conditions
        
        #{   # Lights on
        #    'name': 'lights_on',
        #    'ranges': {
        #        'red':    {'hmin': 0, 'smin': 43, 'vmin': 196, 'hmax': 19, 'smax': 255, 'vmax': 255},
        #        'blue':   {'hmin': 87, 'smin': 72, 'vmin': 0, 'hmax': 173, 'smax': 255, 'vmax': 255},
        #        'yellow': {'hmin': 20, 'smin': 25, 'vmin': 224, 'hmax': 72, 'smax': 255, 'vmax': 255},
        #        'green':  {'hmin': 69, 'smin': 71, 'vmin': 0, 'hmax': 103, 'smax': 255, 'vmax': 255},
        #    }
        #},
        {   # Lights off
            'name': 'lights_off',
            'ranges': {
                'red':   {'hmin': 131, 'smin': 64, 'vmin': 67, 'hmax': 179, 'smax': 255, 'vmax': 255},
                'blue':  {'hmin': 85, 'smin': 95, 'vmin': 0, 'hmax': 159, 'smax': 255, 'vmax': 255},
                'yellow': {'hmin': 15, 'smin': 98, 'vmin': 0, 'hmax': 50, 'smax': 255, 'vmax': 255},
                'green': {'hmin': 55, 'smin': 81, 'vmin': 0, 'hmax': 94, 'smax': 255, 'vmax': 255},
            }
        },
        #{   # Semi-controlled lighting
        #    'name': 'semi_controlled',
        #    'ranges': {
        #        'red':   {'hmin': 0, 'smin': 45, 'vmin': 255, 'hmax': 179, 'smax': 155, 'vmax': 255},
        #        'blue':  {'hmin': 105, 'smin': 88, 'vmin': 0, 'hmax': 166, 'smax': 255, 'vmax': 255},
        #        'yellow': {'hmin': 7, 'smin': 81, 'vmin': 0, 'hmax': 47, 'smax': 255, 'vmax': 255},
        #        'green': {'hmin': 34, 'smin': 137, 'vmin': 192, 'hmax': 104, 'smax': 255, 'vmax': 255},
        #    }
        #},
        {   # Lys på 2.0
            'name': 'lights_on',
            'ranges': {
                'red':   {'hmin': 145, 'smin': 44, 'vmin': 0, 'hmax': 179, 'smax': 255, 'vmax': 255},
                'blue':  {'hmin': 103, 'smin': 34, 'vmin': 0, 'hmax': 161, 'smax': 255, 'vmax': 255},
                'yellow': {'hmin': 19, 'smin': 13, 'vmin': 242, 'hmax': 50, 'smax': 255, 'vmax': 255},
                'green': {'hmin': 53, 'smin': 85, 'vmin': 0, 'hmax': 95, 'smax': 255, 'vmax': 255},
            }
        }
    ]
        
        # Logging
        self.last_log = {c: 0.0 for c in ['red', 'blue', 'yellow', 'green', 'start']} 
        self.log_interval = 2.5 # Log interval in seconds

        self.get_logger().info('CubeTracker started, publishing CubeArray')

    def image_callback(self, msg: Image):
        """Callback for the incoming image. Processes the image to find colored cubes."""
        current_time = time.time()

        if current_time - self.start_time < self.startup_delay: # Wait for startup delay
            return
        
        if current_time - self.last_processed_time < self.process_interval: # Prevents spamming the image processing
            return  #

        self.last_processed_time = current_time
        
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8') # Converts ROS Image to OpenCV BGR-format
        detections = []

        for color in ['red', 'blue', 'yellow', 'green']: # Finds each color cubes in the image
            found = False
            for profile in self.hsv_profiles:
                hsv = profile['ranges'][color]
                _, mask = self.color_finder.update(img, hsv)
                img_out, contours = cvzone.findContours(img, mask)

                if contours: # updates the contours if any are found
                    info = contours[0]
                    cx, cy = info['center']
                    cnt = info['cnt']
                    rect = cv2.minAreaRect(cnt)
                    (_, _), (_, _), angle = rect

                    # Writes variables to the cube array
                    cube = Cube()
                    cube.color = color
                    cube.position = Point(x=float(cx), y=float(cy), z=float((cx*cy)**0.5)) # Cube position in pixel coordinates
                    cube.angle = float(angle)*np.pi/180  # Convert cube angle to radians 
                    detections.append(cube)

                    # Draws the outline and label of the detected cube on the image
                    box = cv2.boxPoints(rect).astype(int)
                    color_bgr = {'red': (0,0,255), 'blue': (255,0,0), 'green': (0,255,0), 'yellow': (0,255,255)}
                    cv2.drawContours(img, [box], 0, color_bgr[color], 2)
                    cv2.putText(img, f"{color.upper()}", (int(cx), int(cy)-10),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.6, color_bgr[color], 2)

                    found = True
                    break  # Stops searching for the color if found

        # Publish all detections
        arr = CubeArray()
        arr.cubes = detections
        self.pub_cubes.publish(arr)
        
        
        self.get_logger().info("Updated CubeArray variables") # Log message in the terminal

        cv2.imwrite('/home/michael/ros2_ws/mega_prosjekt/src/mekatronikk_mega_prosjekt/camera_processor/resource/cube_snapshot.png', img) # Saves a snapshot of the image with contours into cube_snapshot.png
        cv2.imshow('Cube Tracking', img) # Displays the image with contours
        cv2.waitKey(1)
        


def main(args=None): # Main function
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
# Image size and resolution:
    #46.5cm Lengde   640 pixels
    #33cm Høyde      480 pixels