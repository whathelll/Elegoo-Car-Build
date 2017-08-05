# Elegoo-Car-Build
Incremental build of the Elegoo car with Raspberry PI and Arduino

## Raspberry PI Installation
Get the Raspbian Lite Image
https://www.raspberrypi.org/downloads/raspbian/
Install it onto the SD card
https://www.raspberrypi.org/documentation/installation/installing-images/linux.md
```
# Alternative approach
sudo ddrescue -D --force 2017-07-05-raspbian-jessie-lite.img /dev/sdd
```


start the PI
```
vi /etc/default/keyboard	# modify XKBLAYOUT="gb" to "us"
sudo raspi-config 
#enable ssh/camera, change hostname, localisation, timezone
```
configure the wireless
https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md

setup SSH
https://www.raspberrypi.org/documentation/remote-access/ssh/unix.md
https://www.raspberrypi.org/documentation/remote-access/ssh/passwordless.md

```
sudo vi /etc/sysctl.conf
# insert the follow lines at the end to disable ipv6
# net.ipv6.conf.all.disable_ipv6 = 1
# net.ipv6.conf.default.disable_ipv6 = 1
```

Install ROS Kinetic
http://wiki.ros.org/kinetic/Installation/Ubuntu


## Arduino Installation
```
sudo apt-get install arduino
```



This is a combination of various sources adapted for my own learning from basic steps and incrementing to a more advanced car

## References:
https://github.com/wilselby/diy_driverless_car_ROS

https://github.com/clearpathrobotics

http://wiki.ros.org/ROS/Tutorials
