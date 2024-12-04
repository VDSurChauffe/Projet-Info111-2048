2048: 2048.o modele.o
	clang++ --std=c++20 2048.o modele.o -o 2048

2048.o: 2048.cpp
	clang++ --std=c++20 -c 2048.cpp

modele.o: modele.cpp modele.hpp
	clang++ --std=c++20 -c modele.cpp

clean: modele.o 2048.o
	rm -f --std=c++20 modele.o 2048.o
