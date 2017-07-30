# 01 Testing the arduino is connected to the PI

install package to allow us to compile arduino code to /usr/share/arduino
```
sudo apt-get install arduino-core arduino-mk
```

add user to dialout group to allow us to upload code to the arduino board
```
sudo usermod -a -G dialout pi
```


build and upload the file to arduino
```
make
make upload
```

run python file on the Raspberry PI to test that we're receiving signals from the arduino board
```
./test.py
```
