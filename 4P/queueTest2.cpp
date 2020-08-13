/* This test driver tests queue interface methods using C asserts */

#include "queue.h"
#include <cassert>

int main(){
    queue myqueue;
    assert(myqueue.size()==0);
    assert(myqueue.empty()==true);
    
    try {
   	 	myqueue.dequeue();
	}
	catch(EmptyQueueException e){
		cout << "exception caught" << endl;	
	}	

    for(int i=0; i<10000; i++){
        myqueue.enqueue(i);
	}
	assert(myqueue.size()==10000);
	assert(myqueue.front()==0);
	
	myqueue.front()=88;
	assert(myqueue.front()==88);
	
    for(int i=0; i<9999; i++){
        myqueue.dequeue();
	}
	assert(myqueue.size()==1);
	assert(myqueue.front()==9999);
	
	myqueue.front()=88;
	assert(myqueue.front()==88);
	
	myqueue.dequeue();
    assert(myqueue.size()==0);
    assert(myqueue.empty()==true);
    try {
    	myqueue.dequeue();
 	}
 	catch(EmptyQueueException e){
 		cout << "exception caught" << endl;	
 	}	
}

