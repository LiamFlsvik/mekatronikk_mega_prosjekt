#!/bin/bash

SESSION="ros_bringup"

tmux new-session -d -s $SESSION

tmux rename-window -t $SESSION:0 'input_handler'
tmux send-keys -t $SESSION:0 "source install/setup.bash && ros2 launch input_handler input_handler.launch.py" C-m

tmux new-window -t $SESSION:1 -n 'process_handler'
tmux send-keys -t $SESSION:1 "source install/setup.bash && ros2 launch process_handler process_handler.launch.py" C-m

tmux new-window -t $SESSION:2 -n 'camera_tracking'
tmux send-keys -t $SESSION:2 "source install/setup.bash && ros2 launch camera_processor camera_tracking.launch.py" C-m

tmux new-window -t $SESSION:3 -n 'robot_controller'
tmux send-keys -t $SESSION:3 "source install/setup.bash && ros2 launch robot_controller robot_controller.launch.py" C-m

tmux new-window -t $SESSION:4 -n 'scene_handler'
tmux send-keys -t $SESSION:4 "source install/setup.bash && ros2 launch scene_handler scene_handler.launch.py" C-m

tmux attach-session -t $SESSION
