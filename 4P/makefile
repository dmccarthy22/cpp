CXX=g++

tests: stackSampleTest1 stackSampleTest2 queueSampleTest1 queueSampleTest2

all: stack.o queue.o

stack.o: stack.cpp stack.h
	$(CXX) -c stack.cpp -o stack.o

queue.o: queue.cpp queue.h
	$(CXX) -c queue.cpp -o queue.o

stackSampleTest1: stackSampleTest1.cpp stack.cpp stack.h
	$(CXX) stackSampleTest1.cpp stack.cpp -o stackSampleTest1
	
stackSampleTest2: stackSampleTest2.cpp stack.cpp stack.h
	$(CXX) stackSampleTest2.cpp stack.cpp -o stackSampleTest2

queueSampleTest1: queueSampleTest1.cpp queue.cpp queue.h
	$(CXX) queueSampleTest1.cpp queue.cpp -o queueSampleTest1
	
queueSampleTest2: queueSampleTest2.cpp queue.cpp queue.h
	$(CXX) queueSampleTest2.cpp queue.cpp -o queueSampleTest2

clean: 
	rm -f stack.o queue.o stackSampleTest1 stackSampleTest2 queueSampleTest1 queueSampleTest2
