

all: upload
	
upload: compile
	scp test.out pi@192.168.1.24:/home/pi/Hazybot/Robot_2016_2017/ti

compile:
	g++ videocapture_starter.cpp -o test.out `pkg-config --cflags opencv` `pkg-config --libs opencv` -g

