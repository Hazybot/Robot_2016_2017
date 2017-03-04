EXE=../arduinoScript
INO=testSonar.ino
FLAGS=--board arduino:avr:diecimila:cpu=atmega328
UPLOAD_FLAGS=--port /dev/ttyUSB0

all: upload
	

upload:
	$(EXE) --upload $(FLAGS) $(UPLOAD_FLAGS) $(INO)

verify:
	$(EXE) --verify $(FLAGS) $(INO)
