# About

[WIP]

# Screenshots

[WIP]

# How to compile

This Makefile was made for Linux systems so it's only compatible with those. In order to run this code on Windows you need to install WSL or link
the source files and libraries manually. `make` is used to build this code.

Follow these steps to create your executable -

1. Clone this repository
2. Run `make` inside of it
3. Run your executable with `./build/sfml-game`

Use `make clean` to delete the `/build/` and `/out/` directories.

## Why not CMake?

I don't know how to use CMake (and Makefiles). Somehow I managed to create a Makefile that is basically a ticking
ICBM but it works!

# Project structure

* source code - `/src/`
* Makefile - `/Makefile`
* build directory - `/build/`
* out directory (for .o files) - `/out/`
* executable - `/build/sfml-game`
* class files - `/src/Classes/`
* header files - `/src/Headers/`
* configuration files - `/src/Config/`
* assets - `/src/Assets/`

The `/build/` directory, `/out/` directory, and `/build/sfml-game` executable are created when compiling
the code. Maps are generated from images located inside the `/src/Assets/Maps/` directory.
