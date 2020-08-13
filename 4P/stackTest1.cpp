/* This test driver tests stack interface methods using C asserts */

#include "stack.h"
#include <cassert>

int main(){
    stack s;
    
    assert(s.size()==0);
    assert(s.capacity()==8);
    assert(s.empty()==true);
   
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    s.push(10);
    s.push(12);
	
	assert(s.top()==12);
    assert(s.size()==6);
    assert(s.capacity()==8);
    assert(s.empty()==false);
   
	s.top()=0;
	assert(s.top()==0);
   
    s.pop();
	s.pop();
	s.pop();
	assert(s.size()==3);
	assert(s.top()==6);
	
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(9);
	assert(s.size()==8);
	assert(s.capacity()==8);
	assert(s.top()==9);
   
	s.dump(cout);
}

