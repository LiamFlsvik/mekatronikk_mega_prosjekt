 #!/bin/bash

SESSION="ros_bringup"
WORKSPACE=~/ws_mega_prosjekt
KILL_CMD="tmux kill-session -t $SESSION"

tmux has-session -t "$SESSION" 2>/dev/null && tmux kill-session -t "$SESSION"
tmux new-session -d -s "$SESSION" -n main

# Pane 0
tmux split-window -h -t "$SESSION:0"
# Pane 1
tmux split-window -v -t "$SESSION:0.0"
# Pane 2
tmux split-window -v -t "$SESSION:0.1"
# Pane 3
tmux split-window -v -t "$SESSION:0.2"
# Pane 4
tmux split-window -v -t "$SESSION:0.3"

tmux send-keys -t "$SESSION:0.0" "
bash -i -c '
  trap \"$KILL_CMD\" EXIT
  cd $WORKSPACE
  source install/setup.bash
  ros2 launch input_handler input_handler.launch.py
'
" C-m

tmux send-keys -t "$SESSION:0.1" "
bash -i -c '
  trap \"$KILL_CMD\" EXIT
  cd $WORKSPACE
  source install/setup.bash
  ros2 launch process_handler process_handler.launch.py
'
" C-m

tmux send-keys -t "$SESSION:0.2" "
bash -i -c '
  trap \"$KILL_CMD\" EXIT
  cd $WORKSPACE
  source install/setup.bash
  ros2 launch camera_processor camera_tracking.launch.py
'
" C-m

tmux send-keys -t "$SESSION:0.3" "
bash -i -c '
  trap \"$KILL_CMD\" EXIT
  cd $WORKSPACE
  source install/setup.bash
  ros2 launch robot_controller robot_controller.launch.py
'
" C-m

tmux send-keys -t "$SESSION:0.4" "
bash -i -c '
  trap \"$KILL_CMD\" EXIT
  cd $WORKSPACE
  source install/setup.bash
  ros2 launch scene_handler scene_handler.launch.py
'
" C-m

tmux attach-session -t "$SESSION"