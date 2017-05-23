CC_CPP=avr-g++
CC_C=avr-gcc
CC_Lib=avr-ar
CC_EXE=objcopy
CC_Upload=avrdude

arduinoFolder=../lib

CFLAGS=-c -g -Os -w -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=22 -I $(arduinoFolder)
CPPFLAG=-c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=22 -I $(arduinoFolder)
LFLAG=rcsv
LinkFLAGS=-Os -Wl,--gc-sections -mmcu=atmega328p
Link_EFLAGS=-L core -lm
EXEFLAGS=-O ihex -R .eeprom
UploadFLAGS=-v -p m328p -b115200 -c arduino

libName=core.a
ino=testPince

CoreCPP=$(wildcard $(arduinoFolder)/*.cpp)
CoreC=$(wildcard $(arduinoFolder)/*.c)

coreDir=core
binDir=bin

CoreOBJ=$(foreach file, $(CoreCPP:.cpp=.o), $(coreDir)/$(notdir $(file))) $(foreach file, $(CoreC:.c=.o), $(coreDir)/$(notdir $(file)))

all: build

upload: upload_ACM0

upload_ACM0:
	$(CC_Upload) $(UploadFLAGS) -P /dev/ttyACM0 -U flash:w:$(ino).hex

upload_ACM1:
	$(CC_Upload) $(UploadFLAGS) -P /dev/ttyACM1 -U flash:w:$(ino).hex

build: $(ino).hex

$(ino).hex: $(binDir)/$(ino).elf
	$(CC_EXE) $(EXEFLAGS) $(binDir)/$(ino).elf $(ino).hex

$(binDir)/$(ino).elf: $(binDir)/$(ino).o $(coreDir)/$(libName)
	$(CC_C) $(LinkFLAGS) -o $(binDir)/$(ino).elf $(binDir)/$(ino).o $(coreDir)/$(libName) $(Link_EFLAGS)

$(binDir)/$(ino).o: $(ino).cpp
	@mkdir $(binDir) -p
	$(CC_CPP) $(CPPFLAG) -o $(binDir)/$(ino).o $(ino).cpp

$(coreDir)/$(libName): $(CoreOBJ)
	$(CC_Lib) $(LFLAG) $(coreDir)/$(libName) $(coreDir)/*.o

$(coreDir)/%o: $(arduinoFolder)/%cpp
	@mkdir $(coreDir) -p
	$(CC_CPP) $(CPPFLAG) -o $@ $^

$(coreDir)/%o: $(arduinoFolder)/%c
	@mkdir $(coreDir) -p
	$(CC_C) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(coreDir) $(binDir)

mrproper: clean
	rm -f $(ino).hex
