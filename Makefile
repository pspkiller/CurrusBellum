# Makefile tout moche pour linux

CPL=g++
OPT=-Wall -pg
LNK=-lIrrlicht -lX11
EXC=currusBellum
OUT=build
INC=/usr/include/irrlicht/
TARGETS= Arene Char CollisionManager EventManager Irrlicht1 Missile Timer

all: $(TARGETS)
	$(CPL) $(OUT)/Arene.o $(OUT)/Char.o $(OUT)/CollisionManager.o $(OUT)/EventManager.o $(OUT)/Irrlicht1.o $(OUT)/Missile.o $(OUT)/Timer.o -o $(OUT)/$(EXC) $(LNK) $(OPT)

Arene: Arene.h Arene.cpp
	$(CPL) -c Arene.cpp -o $(OUT)/Arene.o $(OPT) -I$(INC)

Char: Char.h Char.cpp
	$(CPL) -c Char.cpp -o $(OUT)/Char.o $(OPT) -I$(INC)

CollisionManager: CollisionManager.h CollisionManager.cpp
	$(CPL) -c CollisionManager.cpp -o $(OUT)/CollisionManager.o $(OPT) -I$(INC)

EventManager: EventManager.h EventManager.cpp
	$(CPL) -c EventManager.cpp -o $(OUT)/EventManager.o $(OPT) -I$(INC)

Irrlicht1: Irrlicht1.cpp
	$(CPL) -c Irrlicht1.cpp -o $(OUT)/Irrlicht1.o $(OPT) -I$(INC)

Missile: Missile.h Missile.cpp
	$(CPL) -c Missile.cpp -o $(OUT)/Missile.o $(OPT) -I$(INC)

Timer: Timer.h Timer.cpp
	$(CPL) -c Timer.cpp -o $(OUT)/Timer.o $(OPT) -I$(INC)

run:
	./$(OUT)/$(EXC)

clean:
	rm $(OUT)/* -rf
