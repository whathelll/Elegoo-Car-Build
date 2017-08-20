# Do the ROS tutorials first
http://wiki.ros.org/ROS/Tutorials

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

# install ncurses on the desktop machine (might have to do it on the PI too when compiling)
```
sudo apt-get install libncurses5-dev
```


# make & upload arduino code
```
cd 03_keyboard_driver/arduino
make
make upload
```

### Run them serparately on the PI and desktop
Desktop: run 2 terminals
```
#terminal 1
roscore

#terminal 2
rosrun keyboard_driver keyboard_driver
```

PI terminal
```
export ROS_MASTER_URI=http://{master node host name}:11311/  #hostname is available when starting roscore
rosrun rosserial_python serial_node.py __name:=L298N_node _port:=/dev/ttyACM0
```
