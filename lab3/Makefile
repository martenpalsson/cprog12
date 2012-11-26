SRCROOT = src
OBJS:= 
INCLUDE:=
CFLAGS = --std=c++0x -Wall

SRC = $(SRCROOT)/object
include $(SRC)/object.mk

SRC = $(SRCROOT)/main
include $(SRC)/game.mk

SRC = $(SRCROOT)/environ
include $(SRC)/terrain.mk

SRC = $(SRCROOT)/character
include $(SRC)/actor.mk
make: all
	@ g++ -o bin/game.elf $(CFLAGS) $(OBJS) -I $(INCLUDE)

clean:
	@ rm bin/*





