import sys
if sys.prefix == '/home/michael/ros2_ws/.venv':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/michael/ros2_ws/mega_prosjekt/src/mekatronikk_mega_prosjekt/install/bringup_robot'
