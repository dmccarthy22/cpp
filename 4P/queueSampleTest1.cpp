/* This test driver tests queue interface methods using C asserts */

#include "queue.h"
#include <cassert>

int main(){
    int tmp; 
    queue myqueue;
    assert(myqueue.size()==0);
    assert(myqueue.empty()==true);
    
    // enqueue 6 items
    myqueue.enqueue(2);
    myqueue.enqueue(4);
    myqueue.enqueue(6);
    myqueue.enqueue(8);
    myqueue.enqueue(10);
    myqueue.enqueue(12);
    assert(myqueue.size()==6);
    assert(myqueue.empty()==false);
    
    // dequeue 2 items
    assert((tmp = myqueue.dequeue()) == 2);
    assert(myqueue.size()==5);
    assert(myqueue.empty()==false);
    
    assert((tmp = myqueue.dequeue()) == 4);
    assert(myqueue.size()==4);
    assert(myqueue.empty()==false);
    
    // enqueue 6 items
    myqueue.enqueue(14);
    myqueue.enqueue(16);
    myqueue.enqueue(18);
    myqueue.enqueue(20);
    myqueue.enqueue(22);
    myqueue.enqueue(24);
    assert(myqueue.empty()==false);
    
    // dequeue 2 items
    assert((tmp = myqueue.dequeue()) == 6);
    assert((tmp = myqueue.dequeue()) == 8);
    assert(myqueue.size()==8);
  
    for(int i=0; i<10000; i++){
        myqueue.dequeue();
        myqueue.enqueue(2);
    }
    assert(myqueue.size()==8);    
}

