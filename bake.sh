#!/bin/bash

PROJECT_NAME="sfml-game"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"

g++ -c src/Main.cpp src/Classes/*
mkdir -p build
g++ *.o -o build/$PROJECT_NAME -I src/Headers $LIBRARIES
rm *.o
