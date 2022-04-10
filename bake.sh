#!/bin/bash

PROJECT_NAME="sfml-game"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"

g++ -c src/Main.cpp
g++ *.o -o build/$PROJECT_NAME $LIBRARIES
rm *.o
