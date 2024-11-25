2048: 2048.o
	clang++ 2048.o -o 2048

2048.o: 2048.cpp
	clang++ -c 2048.cpp

clean:
	rm -f 2048.o 2048