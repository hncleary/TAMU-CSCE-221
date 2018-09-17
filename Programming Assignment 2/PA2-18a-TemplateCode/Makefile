# a simple makefile for compiling C++ files

CC= g++ -std=c++11 -g

# executable: ./PA2
all: PA2

PA2: PA2.o flight.o sort.o
	$(CC) -o PA2 PA2.o flight.o sort.o

PA2.o: PA2.cpp
	$(CC) -c PA2.cpp

flight.o: flight.h flight.cpp
	$(CC) -c flight.cpp

sort.o: sort.h sort.cpp
	$(CC) -c sort.cpp

clean:
	/bin/rm -f *.o PA2

# the directory 221-A2-code must exist
tar:
	@ /bin/rm -f *.o
	@ if [ ! -d ../221-A2-code ]; then \
	echo "Error: the directory 221-A2-code does not exist"; \
	exit 1; \
	else \
	cd ..; tar cvf 221-A2-code-submit.tar 221-A2-code; \
	fi

