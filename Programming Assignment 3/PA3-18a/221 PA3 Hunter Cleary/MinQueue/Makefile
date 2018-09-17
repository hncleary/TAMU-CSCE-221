all: MinQueue

MinQueue: DoublyLinkedList.o MinQueue.o
	g++ -std=c++11 DoublyLinkedList.o MinQueue.o -o MinQueue

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -std=c++11 -c DoublyLinkedList.cpp

MinQueue.o: MinQueue.cpp DoublyLinkedList.h
	g++ -std=c++11 -c MinQueue.cpp

clean:
	rm *.o MinQueue
