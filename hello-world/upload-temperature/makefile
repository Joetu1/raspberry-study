#make file of raspberri pi,cross
# 指定编译器
# CC=arm-linux-gnueabihf-gcc  

# LD=$(CC)
#可执行文件
# TARGET=blink
# 依赖文件
# OBJECT=blink.o 

RASPBERRY_PI_DIR=/home/joetu/raspberry
WIRING_PI_INCLUDE_PATH=$(RASPBERRY_PI_DIR)/wiringPi/wiringPi
#此lib是先在 目标平台上生成的
WIRING_PI_LIB_PATH=$(RASPBERRY_PI_DIR)/raspberry-dev/wiringPi-lib


# $(TARGET):$(OBJECT)
# 	$(LD) -o $(TARGET) $(OBJECT) -L$(WIRING_PI_LIB_PATH) -lwiringPi

# blink.o:blink.c 
# 	$(CC) -o blink.o -c blink.c -I$(WIRING_PI_INCLUDE_PATH)
	

# clean:
# 	rm -f $(TARGET) $(OBJECT)



CC = arm-linux-gnueabihf-gcc  
  
ROOTPATH=../..
INCLUDE = -I$(ROOTPATH)/easylogger/plugins/ -I$(ROOTPATH)/easylogger/inc -I$(WIRING_PI_INCLUDE_PATH)
LIB=-lpthread -lwiringPi -L$(WIRING_PI_LIB_PATH)

OBJ += $(patsubst %.c, %.o, $(wildcard *.c))
OBJ += $(patsubst %.c, %.o, $(wildcard $(ROOTPATH)/easylogger/src/*.c))
OBJ += $(patsubst %.c, %.o, $(wildcard $(ROOTPATH)/easylogger/port/*.c))
# OBJ += $(patsubst %.c, %.o, $(wildcard $(ROOTPATH)/easylogger/plugins/file/elog_file.c))

CFLAGS = -O0 -g3 -Wall
target = blink

all:$(OBJ)
	$(CC) out/*.o -o $(target) $(LIB)
	mv $(target) out
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	mv $@ out	
clean:
	rm -rf out/*