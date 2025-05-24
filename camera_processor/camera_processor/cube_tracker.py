import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge
import cv2
import cvzone
from cvzone.ColorModule import ColorFinder
import os
import time
import numpy as np

class CubeTracker(Node): #Cube tracker class to find and track colored cubes from a continous video stream or a static image.
    def __init__(self):
        super().__init__('cube_tracker') # Initialize the CubeTracker node

        self.sub = self.create_subscription(Image, '/camera/image_raw', self.image_callback, 10)
        self.pub_red = self.create_publisher(Point, 'red_cube_position', 10)
        self.pub_blue = self.create_publisher(Point, 'blue_cube_position', 10)
        self.pub_yellow = self.create_publisher(Point, 'yellow_cube_position', 10)
        self.pub_green = self.create_publisher(Point, 'green_cube_position', 10)
        # Initialize the CvBridge to convert ROS images to OpenCV format
        self.bridge = CvBridge()
        self.color_finder = ColorFinder(False)
                   
        #self.color_ranges = { # Define HSV color ranges for different cubes (Lights off)
        #    'red':   {'hmin': 134, 'smin': 131, 'vmin': 0, 'hmax': 179, 'smax': 186, 'vmax': 255},
        #    'blue':  {'hmin': 102, 'smin': 164, 'vmin': 124, 'hmax': 165, 'smax': 244, 'vmax': 255},
        #    'yellow': {'hmin': 9, 'smin': 103, 'vmin': 101, 'hmax': 28, 'smax': 176, 'vmax': 239},
        #    'green': {'hmin': 48, 'smin': 64, 'vmin': 53, 'hmax': 91, 'smax': 117, 'vmax': 107},
        #}
        self.color_ranges = { # Define HSV color ranges for different cubes (Lights on)
            'red':   {'hmin': 0, 'smin': 57, 'vmin': 243, 'hmax': 12, 'smax': 135, 'vmax': 255},
            'blue':  {'hmin': 93, 'smin': 184, 'vmin': 200, 'hmax': 108, 'smax': 222, 'vmax': 255},
         #   'yellow': {'hmin': 0, 'smin': 1, 'vmin': 244, 'hmax': 31, 'smax': 38, 'vmax': 249},
            'green': {'hmin': 31, 'smin': 29, 'vmin': 139, 'hmax': 78, 'smax': 109, 'vmax': 244},
        }
        self.last_log_times = { # Sets the values
            'red': 0,
            'blue': 0,
         #   'yellow': 0,
            'green': 0
        }
        self.log_interval = 2.5  # Timer between logs in seconds
        self.get_logger().info("CubeTracker node started – red, blue, yellow, green cubes")

    def image_callback(self, msg):  # Callback function to process incoming images from the camera
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        for color, hsv in self.color_ranges.items():
            imgColor, mask = self.color_finder.update(img, hsv)
            imgContour, contours = cvzone.findContours(img, mask)

            if contours:
                cx, cy = contours[0]['center']
                area = contours[0]['area']
                cnt = contours[0]['cnt']
            
                # Prints an outline of the cubes
                rect = cv2.minAreaRect(cnt)
                box = cv2.boxPoints(rect)
                box = np.intp(box)

                (center_x, center_y), (width, height), angle = rect

                # Estimates the height of the cube based on its area
                x_len = max(width, height)
                y_len = min(width, height)
                z_height = (x_len * y_len) ** 0.5  # Estimert høyde ut fra areal

                # Writes the cube data into an array
                cube_data = {
                    'x_length': round(x_len, 2),
                    'y_length': round(y_len, 2),
                    'z_height': round(z_height, 2),
                    'center': (int(center_x), int(center_y)),
                    'color': color,
                    'rotation': round(angle, 2)
                }

                color_bgr = {
                    'red':   (0, 0, 255),
                    'blue':  (255, 0, 0),
              #      'yellow': (0, 255, 255),
                    'green': (0, 255, 0)
                }.get(color, (255, 255, 255))

                # Tegn kontur og tekst
                cv2.drawContours(img, [box], 0, color_bgr, 2)
                cv2.putText(img, color.upper(), (int(center_x), int(center_y - 10)),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, color_bgr, 2)

                current_time = time.time()
                if current_time - self.last_log_times[color] >= self.log_interval:
                    self.get_logger().info(f"{color.upper()} CUBE DATA: {cube_data}")
                    self.last_log_times[color] = current_time

                # Publiser ROS Point (sentrert)
                point = Point()
                point.x = float(center_x)
                point.y = float(center_y)
                point.z = float(area)
    
                if color == 'red':
                    self.pub_red.publish(point)
                elif color == 'blue':
                    self.pub_blue.publish(point)
               # elif color == 'yellow':
               #     self.pub_yellow.publish(point)
                elif color == 'green':
                    self.pub_green.publish(point)

        # Vis bilde
        cv2.imshow("Cube Tracking", img)
        cv2.waitKey(1)


def main(args=None): # Main function to initialize the ROS node and start the CubeTracker
    rclpy.init(args=args)
    node = CubeTracker()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__': 
    main()
