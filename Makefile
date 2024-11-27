2048: 2048.o modele.o
	g++ -L SDL2/lib 2048.o modele.o -o 2048 -lmingw32 -lSDL2main -lSDL2

2048.o: 2048.cpp
	g++ -I SDL2/include -c 2048.cpp

modele.o: modele.cpp modele.hpp
	g++ -c modele.cpp

clean: modele.o 2048.o
	rm -f modele.o 2048.o