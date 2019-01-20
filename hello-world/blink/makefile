#make file of raspberri pi,cross
CC=arm-linux-gnueabihf-gcc  
LD=$(CC)

TARGET=blink
OBJECT=blink.o 

RASPBERRY_PI_DIR=/home/joetu/raspberry
WIRING_PI_INCLUDE_PATH=$(RASPBERRY_PI_DIR)/wiringPi/wiringPi
#此lib是先在 目标平台上生成的
WIRING_PI_LIB_PATH=$(RASPBERRY_PI_DIR)/raspberry-dev/wiringPi-lib


$(TARGET):$(OBJECT)
	$(LD) -o $(TARGET) $(OBJECT) -L$(WIRING_PI_LIB_PATH) -lwiringPi

blink.o:blink.c 
	$(CC) -o blink.o -c blink.c -I$(WIRING_PI_INCLUDE_PATH)
	

clean:
	rm -f $(TARGET) $(OBJECT)