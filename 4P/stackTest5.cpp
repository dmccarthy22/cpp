/* This test driver tests stack interface methods using C asserts */

#include "stack.h"
#include <cassert>

int main(){
    stack s1;
	
	for(int i=1; i<=1050; i++)
		s1.push(i);

    assert(s1.size()==1050);
	assert(s1.capacity()==2048);
	assert(s1.top()==1050);
	
	stack s2;
    assert(s2.size()==0);
	assert(s2.capacity()==8);

    // assignment operator 
    s2 = s1;
    assert(s2.size()==1050);
	assert(s2.capacity()==2048);
	assert(s2.top()==1050);
	

	for(int i=1; i<1050; i++)
		s2.pop();
    assert(s2.size()==1);
	assert(s2.capacity()==2048);
	assert(s2.top()==1);

    assert(s1.size()==1050);
	assert(s1.capacity()==2048);
	assert(s1.top()==1050);
	

	for(int i=1; i<=1050; i++)
		s2.push(i);
    assert(s2.size()==1051);
	assert(s2.capacity()==2048);
	
    s1 = s2;
    assert(s2.size()==1051);
	assert(s2.capacity()==2048);
   
	
}

