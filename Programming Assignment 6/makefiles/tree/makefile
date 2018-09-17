all: main.o text_freq.o
	g++ -std=c++11 main.o text_freq.o -o main
text_freq.o: text_freq.cpp text_freq.h
	g++ -std=c++11 -g -c text_freq.cpp
main.o: main.cpp my_map.h BTree.h key_value.h text_freq.o
	g++ -std=c++11 -g -c main.cpp