CC=g++
LIBFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
HEADERS=src/Headers
BUILDFOLDER=build
EXECUTABLE=sfml-game

$(EXECUTABLE): out/Main.o out/BackgroundRect.o out/Block.o out/Bullet.o out/Collision.o out/Entity.o out/Game.o out/Player.o
	mkdir -p $(BUILDFOLDER)
	$(CC) out/Main.o out/BackgroundRect.o out/Block.o out/Bullet.o out/Collision.o out/Entity.o out/Game.o out/Player.o -o $(BUILDFOLDER)/$(EXECUTABLE) -I ${HEADERS} ${LIBFLAGS}

out/Main.o: src/Main.cpp
	mkdir -p out
	$(CC) -c src/Main.cpp -o out/Main.o

out/BackgroundRect.o: src/Classes/BackgroundRect.cpp
	$(CC) -c src/Classes/BackgroundRect.cpp -o out/BackgroundRect.o

out/Block.o: src/Classes/Block.cpp
	$(CC) -c src/Classes/Block.cpp -o out/Block.o

out/Bullet.o: src/Classes/Bullet.cpp
	$(CC) -c src/Classes/Bullet.cpp -o out/Bullet.o

out/Collision.o: src/Classes/Collision.cpp
	$(CC) -c src/Classes/Collision.cpp -o out/Collision.o

out/Entity.o: src/Classes/Entity.cpp
	$(CC) -c src/Classes/Entity.cpp -o out/Entity.o

out/Game.o: src/Classes/Game.cpp
	$(CC) -c src/Classes/Game.cpp -o out/Game.o

out/Player.o: src/Classes/Player.cpp
	$(CC) -c src/Classes/Player.cpp -o out/Player.o

clean:
	rm -rf build out
