# About

[WIP]

# Screenshots

[WIP]

# How to compile

This code was made for Linux systems so it's only compatible with those. In order to run this code on Windows you need to install WSL or link
the source files and libraries manually. The script `/bake.sh` is used to compile the code.

## Using `bake.sh`

Follow these steps to create your executable -

1. Add a run flag to the script with `chmod +x ./bake.sh`
2. Run the script - `./bake.sh`
3. Run the compiled file - `./build/sfml-game`

## Why not Makefiles or CMake?

I don't know how to use them. Will hopefully fix in the future!

# Project structure

* source code - `/src/`
* build directory - `/build/`
* executable - `/build/sfml-game`
* class files - `/src/Classes/`
* header files - `/src/Headers/`
* assets - `/src/Assets/`

The `/build/` directory (with the executable) is created when compiling the code.
