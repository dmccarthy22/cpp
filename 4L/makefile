CXX=g++

all: queue.o queueTest


queue.o: queue.cpp queue.h
	$(CXX) -c queue.cpp

queueTest: queueTest.cpp queue.cpp queue.h
	$(CXX) queueTest.cpp queue.cpp -lgtest -lpthread -o queueTest

clean:
	rm -f queueTest queue.o
