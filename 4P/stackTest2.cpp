/* This test driver tests stack interface methods using C asserts */

#include "stack.h"
#include <cassert>

int main(){
    stack s;
    
    assert(s.size()==0);
    assert(s.capacity()==8);
    assert(s.empty()==true);
    
    try {
        s.pop();
    } catch ( EmptyStackException e ){
        cout << "exception caught \n";
    }
   
    assert(s.size()==0);
    assert(s.capacity()==8);
    assert(s.empty()==true);
   
    for(int i=0; i<10000; i++)
		s.push(i);
	
    assert(s.size()==10000);
    assert(s.top()==9999);
   
    s.pop();
	s.pop();
	
    assert(s.size()==9998);
    assert(s.top()==9997);
	
    for(int i=0; i<9997; i++)
		s.pop();
   
	assert(s.size()==1);
	s.pop();
    assert(s.size()==0);
    assert(s.empty()==true);
    
    try {
        s.pop();
    } catch ( EmptyStackException e ){
        cout << "exception caught \n";
    }
}

