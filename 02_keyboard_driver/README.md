# Manual Keyboard Driving



### checkout rosserial into catkin_ws/src and switch branch to match ROS version
```
cd <ws>/src
git clone https://github.com/ros-drivers/rosserial.git
git checkout indigo-devel
cd <ws>
catkin_make
```

once built
```
cd ~/sketchbook/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py .
```

# make & upload arduino code
```
cd 02_keyboard_driver/arduino
make
make upload
```

### Run them serparately on the PI
terminal 1
```
roscore
rosrun rosserial_python serial_node.py __name:=L298N_node _port:=/dev/ttyACM0
```
