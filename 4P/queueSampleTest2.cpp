/* This test driver tests queue interface methods using C asserts */

#include "queue.h"
#include <cassert>

int main(){
    int tmp; 
    queue q1;
    
	for (int i=0; i<8; i++)
		q1.enqueue(i*2);
  
    assert(q1.size()==8);
	assert(q1.capacity()==8);
	
	assert(q1.dequeue()==0);
	assert(q1.dequeue()==2);
	assert(q1.dequeue()==4);
    assert(q1.size()==5);
	
	q1.enqueue(7);
	q1.enqueue(9);
	q1.enqueue(11);
    assert(q1.size()==8);

    // copy constructor 
	queue q2 = q1;
	q1.dump(cout);
	q2.dump(cout);

	q1.enqueue(20);
	q1.enqueue(30);
    assert(q1.size()==10);
	assert(q1.capacity()==16);
	
	
	q1.front() = 100;
	assert(q1.front()==100);
	
	assert(q1.dequeue()==100);
	assert(q1.dequeue()==8);
	assert(q1.dequeue()==10);
	assert(q1.size()==7);
	
	// assignment operator 
	q2 = q1;
	q1.dump(cout);
	q2.dump(cout);
	
	q1.dequeue();
	q2.enqueue(88);
	q1.dump(cout);
	q2.dump(cout);
}