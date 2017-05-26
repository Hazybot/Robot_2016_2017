EXE=../arduinoScript
INO=extern.ino
FLAGS=--board arduino:avr:uno
UPLOAD_FLAGS=--port /dev/ttyACM0

all: upload
	

upload:
	$(EXE) --upload $(FLAGS) $(UPLOAD_FLAGS) $(INO)

verify:
	$(EXE) --verify $(FLAGS) $(INO)
