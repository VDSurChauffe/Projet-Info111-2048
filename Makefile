2048: 2048.o modele.o
	clang++ 2048.o modele.o -o 2048

2048.o: 2048.cpp
	clang++ -c 2048.cpp

modele.o: modele.cpp modele.hpp
	clang++ -c modele.cpp

clean: modele.o 2048.o
	rm -f modele.o 2048.o
