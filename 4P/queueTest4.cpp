/* This test driver tests queue interface methods using C asserts */

#include "queue.h"
#include <cassert>

int main(){
    queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
    assert(q1.size()==7);
	assert(q1.capacity()==8);
	assert(q1.front()==1);

    // copy constructor 
	queue q2 = q1;
    assert(q2.size()==7);
	assert(q2.capacity()==8);
	assert(q2.front()==1);
    
	q1.enqueue(20);
	q1.enqueue(30);
    assert(q1.size()==9);
	assert(q1.capacity()==16);
	assert(q1.front()==1);
	
    assert(q2.size()==7);
	assert(q2.capacity()==8);
	assert(q2.front()==1);
	
	q2.dequeue();
    assert(q2.size()==6);
	assert(q2.capacity()==8);
	assert(q2.front()==2);
	
    assert(q1.size()==9);
	assert(q1.capacity()==16);
	assert(q1.front()==1);
}



