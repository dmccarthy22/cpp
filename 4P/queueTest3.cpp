/* This test driver tests queue interface methods using C asserts */

#include "queue.h"
#include <cassert>

int main(){
    queue myqueue;
 
 	assert(myqueue.size()==0); 
    assert(myqueue.capacity()==8);
 
    for(int i=0; i<8; i++){
        myqueue.enqueue(i);
    }
    assert(myqueue.size()==8); 
	assert(myqueue.capacity()==8); 
	
	myqueue.enqueue(0);
    assert(myqueue.size()==9); 
	assert(myqueue.capacity()==16); 
 
    for(int i=0; i<7; i++){
        myqueue.enqueue(i);
    }  
	
    assert(myqueue.size()==16); 
	assert(myqueue.capacity()==16);
	
	myqueue.enqueue(0);
    assert(myqueue.size()==17); 
	assert(myqueue.capacity()==32); 

    for(int i=0; i<15; i++){
        myqueue.enqueue(i);
    }  

    assert(myqueue.size()==32); 
	assert(myqueue.capacity()==32); 
	
	myqueue.enqueue(0);
    assert(myqueue.size()==33); 
	assert(myqueue.capacity()==64); 
	
    for(int i=0; i<100000; i++){
        myqueue.enqueue(i);
    }  
	assert(myqueue.size()==100033);
	assert(myqueue.capacity()==131072);
}

