CXX=g++

all: wordcheck wordfreq 

wordcheck: wordcheck.cpp 
	$(CXX) wordcheck.cpp -o wordcheck

words: words.cpp 
	$(CXX) wordfreq.cpp -o wordfreq

clean:
	rm -f *.o wordcheck wordfreq

