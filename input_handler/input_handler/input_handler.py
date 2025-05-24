#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from pynput import keyboard
import threading
import json

from process_msgs.msg import KeyEvent
from builtin_interfaces.msg import Time
from rclpy.time import Time as RclpyTime

class KeyboardInputHandler(Node):
    def __init__(self):
        super().__init__('keyboard_input_handler')
        self.publisher_ = self.create_publisher(KeyEvent, '/active_keys', 10)
        
        self.active_keys = set()
        self.lock = threading.Lock()

        #define valid keys to monitor
        self.valid_keys = {
            'w',
            'space',
            'enter'
        }
        self.timer = self.create_timer(0.05, self.publish_keys)
        self.keyboard_listener = keyboard.Listener(
            on_press=self.on_press,
            on_release=self.on_release
        )
        self.keyboard_listener.start()

        def on_press(self, key):
            try:
                with self.lock:
                    key_str = key.char if hasattr(key, 'char') else f'<{key._name_}>'
                    if key_str in self.valid_keys:
                        self.active_keys.add(key_str)
            except AttributeError:
                pass

    def on_release(self, key):
        try:
            with self.lock:
                key_str = key.char if hasattr(key, 'char') else f'<{key._name_}>'
                if key_str in self.valid_keys:
                    self.active_keys.discard(key_str)
        except AttributeError:
            pass

    def publish_keys(self):
        with self.lock:
            msg = KeyEvent()
            msg.active_keys = list(self.active_keys)
            msg.stamp = self.get_clock().now().to_msg()
            self.publisher_.publish(msg)
            self.display_status()

    def display_status(self):
        status = f"""
        Active Keys: {self.active_keys}
        """
        print("\033[2J\033[H")
        print(status)

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