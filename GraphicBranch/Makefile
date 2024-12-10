2048: 2048.o modele.o
	g++ -L SDL2/lib -L SDL_ttf/lib 2048.o modele.o -o 2048 -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

2048.o: 2048.cpp
	g++ -I SDL2/include -I SDL_ttf/include -c 2048.cpp

modele.o: modele.cpp modele.hpp
	g++ -I SDL2/include -I SDL_ttf/include -c modele.cpp

clean: modele.o 2048.o
	rm -f modele.o
	rm -f 2048.o