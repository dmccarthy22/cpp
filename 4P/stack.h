#include <iostream>
#include <cassert>
using namespace std;

#define INITCAP 8
#define TYPE int

class EmptyStackException{};

class stack{
public:
    // constructor with default capacity value
    stack(int=INITCAP);
    
    // copy constructor
    stack(const stack&);
    
    // assignment operator
    stack& operator=(const stack&);
    
    // destructor
    ~stack();
    
    // push an element, expanding if necessary;
    void push(const TYPE x);
    
    // remove and element; throw EmptyStackException when stack is empty
    void pop();
    
    // return a reference to the top element without popping; throw EmptyStackException when stack is empty
    TYPE& top();
    
    // return true if the stack is empty, false otherwise
    bool empty();
    
    // return the number of elements currently on the stack
    int  size();
    
    // return the current capacity of the stack
    int  capacity();
	
    // output stack elements from stack top to stack bottom
	// elements are separated with a white space. 
    void dump(ostream &os);
    
private:
    TYPE * _arr;     // pointer to dynamic integer array
    int _tos;       // index to top of stack
    int _capacity;  // current capacity 
};
 
