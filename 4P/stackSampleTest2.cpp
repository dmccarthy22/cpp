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
    assert(s.size()==6);
    assert(s.capacity()==8);
    assert(s.empty()==false);
    
    s.push(14);
    s.push(16);
    s.push(100);
    
    assert(s.size()==9);
    assert(s.capacity()==16);
    
    assert(s.top()==100);
    s.pop();
    assert(s.top()==16);
    s.pop();
    assert(s.top()==14);
    s.pop();
    assert(s.size()==6);
    assert(s.capacity()==16);
    
    // testing copy constructor
    stack t(s);
    assert(t.size()==s.size());
    s.pop();
    assert(t.top()==12);
    assert(s.top()==10);
    
    s.pop();
    s.pop();
    
    // testing assignment operator
    t = s;
    assert(t.top()==6);
    
    try {
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
    } catch  ( EmptyStackException e ){
        cout << "exception caught \n";
    }
}

