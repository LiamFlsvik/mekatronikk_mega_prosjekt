#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from pynput import keyboard
import threading

from process_msgs.msg import KeyEvent

class KeyboardInputHandler(Node):
    def __init__(self):
        super().__init__('keyboard_input_handler')
        self.publisher_    = self.create_publisher(KeyEvent, '/active_keys', 10)
        self.active_keys   = set()
        self.lock          = threading.Lock()
        self.valid_keys    = {'w', '<space>', '<enter>'}
        self.timer         = self.create_timer(0.05, self.publish_keys)

        # now correctly reference the class methods
        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_press,
            on_release=self.on_release
        )
        self.keyboard_listener.start()
        self.get_logger().info('keyboard_input_handler ready – publishing active_keys at 20 Hz')

    def on_press(self, key):
        try:
            key_str = key.char if hasattr(key, 'char') else f'<{key._name_}>'
            with self.lock:
                if key_str in self.valid_keys:
                    self.active_keys.add(key_str)
        except AttributeError:
            pass

    def on_release(self, key):
        try:
            key_str = key.char if hasattr(key, 'char') else f'<{key._name_}>'
            with self.lock:
                if key_str in self.valid_keys:
                    self.active_keys.discard(key_str)
        except AttributeError:
            pass

    def publish_keys(self):
        with self.lock:
            msg = KeyEvent()
            msg.active_keys = list(self.active_keys)
            self.publisher_.publish(msg)
            self.display_status()

    def display_status(self):
        print("\033[2J\033[HActive Keys:", self.active_keys)

    def __del__(self):
        self.keyboard_listener.stop()

def main(args=None):
    rclpy.init(args=args)
    node = KeyboardInputHandler()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
