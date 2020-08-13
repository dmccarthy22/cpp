/* This test driver tests stack interface methods using C asserts */

#include "stack.h"
#include <cassert>

int main(){
	stack s;

	assert(s.size()==0);
	assert(s.capacity()==8);

	for(int i=0; i<8; i++){
		s.push(i);
	}
	assert(s.size()==8);
	assert(s.capacity()==8);

	s.push(0);
	assert(s.size()==9);
	assert(s.capacity()==16);


	for(int i=0; i<7; i++){
		s.push(i);
	}

	assert(s.size()==16);
	assert(s.capacity()==16);

	s.push(0);
	assert(s.size()==17);
	assert(s.capacity()==32);

	for(int i=0; i<15; i++){
		s.push(i);
	}

	assert(s.size()==32);
	assert(s.capacity()==32);

	s.push(0);
	assert(s.size()==33);
	assert(s.capacity()==64);

	for(int i=0; i<100000; i++){
		s.push(i);
	}
	assert(s.size()==100033);
	assert(s.capacity()==131072);
}
