CC=g++
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
HEADERS=src/Headers
BUILDFOLDER=build
EXECUTABLE=sfml-game

$(EXECUTABLE): Main.o BackgroundRect.o Block.o Bullet.o Collision.o Entity.o Game.o Player.o
	mkdir -p $(BUILDFOLDER)
	$(CC) Main.o BackgroundRect.o Block.o Bullet.o Collision.o Entity.o Game.o Player.o -o $(BUILDFOLDER)/$(EXECUTABLE) -I ${HEADERS} ${LIBFLAGS}

Main.o: src/Main.cpp
	$(CC) -c src/Main.cpp -o Main.o

BackgroundRect.o: src/Classes/BackgroundRect.cpp
	$(CC) -c src/Classes/BackgroundRect.cpp -o BackgroundRect.o

Block.o: src/Classes/Block.cpp
	$(CC) -c src/Classes/Block.cpp -o Block.o

Bullet.o: src/Classes/Bullet.cpp
	$(CC) -c src/Classes/Bullet.cpp -o Bullet.o

Collision.o: src/Classes/Collision.cpp
	$(CC) -c src/Classes/Collision.cpp -o Collision.o

Entity.o: src/Classes/Entity.cpp
	$(CC) -c src/Classes/Entity.cpp -o Entity.o

Game.o: src/Classes/Game.cpp
	$(CC) -c src/Classes/Game.cpp -o Game.o

Player.o: src/Classes/Player.cpp
	$(CC) -c src/Classes/Player.cpp -o Player.o

clean:
	rm -rf build *.o
