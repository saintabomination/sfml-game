#!/bin/bash

PROJECT_NAME="sfml-game"

g++ -c src/Main.cpp
g++ *.o -o build/$PROJECT_NAME
rm *.o
