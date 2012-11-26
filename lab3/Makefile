SRCROOT = src
OBJS:= 
INCLUDE:=
CFLAGS = --std=c++0x -Wall

SRC = $(SRCROOT)/main
include $(SRC)/game.mk

SRC = $(SRCROOT)/character
include $(SRC)/character.mk

SRC = $(SRCROOT)/object
include $(SRC)/object.mk


make: 
	@ g++ -o bin/game.elf $(CFLAGS) $(OBJS) -I $(INCLUDE)

clean:
	@ rm bin/*





