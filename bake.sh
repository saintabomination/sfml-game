#!/bin/bash

PROJECT_NAME="sfml-game"
LIBRARIES="-lsfml-graphics -lsfml-window -lsfml-system"

if [[ $1 == "" ]]
then
  g++ -c src/Main.cpp src/Classes/*
  mkdir -p build
  g++ *.o -o build/$PROJECT_NAME -I src/Headers $LIBRARIES
  rm *.o
elif [[ $1 == "cc" ]]
then
  > src/Headers/${2^}.h
  > src/Classes/${2^}.cpp
elif [[ $1 == "rc" ]]
then
  rm src/Headers/${2^}.h
  rm src/Classes/${2^}.cpp
else
  echo "Invalid argument!"
fi
