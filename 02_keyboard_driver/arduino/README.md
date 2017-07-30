# How to make and upload

Follow  http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

Arduino installs ~/sketchbook
```
[DEFAULT]            USER_LIB_PATH = /home/pi/sketchbook/libraries
```
so we go into here and type
```
rosrun rosserial_arduino make_libraries.py .
```

This will create a ros_lib which matches the library we have in our Makefile
