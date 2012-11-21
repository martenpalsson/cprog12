SRCROOT = src
OBJS:= 
INCLUDE:=
CFLAGS = --std=c++0x -Wall

SRC = $(SRCROOT)/object
include $(SRC)/object.mk

SRC = $(SRCROOT)/main
include $(SRC)/game.mk


make:
	@ g++ -o bin/game.elf $(CFLAGS) $(OBJS) -I $(INCLUDE)

clean:
	@ rm bin/*





