#include <iostream>
#include <cassert>
using namespace std;

#define INITCAP 8
#define TYPE int

class EmptyQueueException{};

class queue{
public:
    // constructor with default capacity value
    queue(int=INITCAP);
    
    // copy constructor
    queue(const queue&);
    
    // assignment operator
    queue& operator=(const queue&);
    
    // destructor
    ~queue();
    
    // add an element to the end of queue (expand if necessary)
    void enqueue(const TYPE); 
  
    // remove an element from the front of queue 
    TYPE dequeue();
	
    // access the element at queue front; does not remove the element
    TYPE& front();
  
    // return true if the queue is empty, false otherwise
    bool empty();
    
    // return the number of elements currently in the queue
    int  size();
    
    // return the current capacity of the queue
    int  capacity();
	
    // output queue elements from queue front to queue end
	// elements are separated with a white space. 
    void dump(ostream &os);
	
private:
    TYPE * _arr;     // pointer to dynamic integer array
    int _front;      // index to the front element of queue
    int _size;       // number of current elements in queue
    int _capacity;   // current capacity 
};
