/* This test driver tests stack interface methods using C asserts */

#include "stack.h"
#include <cassert>

int main(){
    stack s1;
    
    assert(s1.size()==0);
    assert(s1.capacity()==8);
    assert(s1.empty()==true);
   
	for( int i = 0; i < 15; i++ ){
		s1.push(i);
	}

	assert(s1.size()==15);
	assert(s1.empty()==false);
	assert(s1.capacity()==16);

	stack s2 = s1;

	assert(s2.size()==15);
	assert(s2.capacity()==16);
	assert(s2.empty()==false);

	for(int i = 0; i < 15; i++){
		assert( s2.top() == s1.top() );
		s2.pop();
		s1.pop();
	}

	assert(s1.size()==0);
	assert(s1.capacity()==16);

	assert(s2.size()==0);
	assert(s2.capacity()==16);
	
 
	for( int i = 0; i < 100; i++ ){
		s1.push(i);
	}
	
	assert(s1.size()==100);
	assert(s1.capacity()==128);
	
	assert(s2.size()==0);
	assert(s2.capacity()==16);
	
	for( int i = 0; i < 8; i++ ){
		s2.push(i);
	}
	
	assert(s2.size()==8);
	assert(s2.capacity()==16);
	
	assert(s1.size()==100);
	assert(s1.capacity()==128);
}

