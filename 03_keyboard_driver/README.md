# Manual Keyboard Driving

Follow the "Adding Released Packages" section to add geometry_msgs, rosserial, rosserial_arduino
http://wiki.ros.org/ROSberryPi/Installing%20ROS%20Kinetic%20on%20the%20Raspberry%20Pi

e.g.
```
cd ~/ros_catkin_ws
rosinstall_generator geometry_msgs rosserial rosserial_arduino --rosdistro kinetic --deps --wet-only --tar > kinetic-custom_ros.rosinstall
.....
```

once built
```
cd ~/sketchbook/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py .
```

# make & upload arduino code
```
cd 03_keyboard_driver/arduino
make
make upload
```

### Run them serparately on the PI
terminal 1
```
roscore
rosrun rosserial_python serial_node.py __name:=L298N_node _port:=/dev/ttyACM0
```
