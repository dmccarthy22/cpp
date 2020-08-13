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
   
    // testing copy constructor
    stack t(s);
    
	assert(t.size()==s.size());
    t.dump(cout);
	s.dump(cout);
	
	t.push(88);
    assert(t.top()==88);
	s.pop();
	assert(s.top()==10);
    
    t.dump(cout);
	s.dump(cout);
}

