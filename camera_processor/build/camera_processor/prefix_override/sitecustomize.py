import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/michael/ros2_ws/mega_prosjekt/src/mekatronikk_mega_prosjekt/camera_processor/install/camera_processor'
