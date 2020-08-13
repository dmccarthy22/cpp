/* CS515 Assignment 1
File: evaluation.cpp
Name: Dan McCarthy
Section: 4
Collaboration Declaration:
          I received assistance from TA Ethan, the PAC, and collaborated with other students in PAC (Paul Ackels)

*/

// infix expression evaluation
// implemented with STL vector
// evalues expression with multiple digit numbers, * / + - and {} [] () paratheis
// assume the expression is well formatted with balanced braces.

#include <iostream>
#include <stack>
#include <string>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstring>
#include<cctype>


using namespace std;

//----------------------------------------------------------------
// Generates a stack of string tokens representing postfix
// notation for the input line
void generateRPN(string line, stack<string> &postfix);

//----------------------------------------------------------------
// Returns a the result of evaluating the passed postfix token
// stack as a decimal string
string evaluateRPN(stack<string> &postfix)
{
  stack<string> post;
  while(!postfix.empty()){
    post.push(postfix.top());
    postfix.pop();
  }
  int a;
  int b;
  stack<string> mystack;
  if (post.size() == 1){
    return post.top();
  }
  while(!post.empty()){

    if(post.top()=="+"){
      post.pop();
      a = stoi(mystack.top());
      mystack.pop();
      b = stoi(mystack.top());
      mystack.pop();
      mystack.push(to_string(b+a));
    }
    else if (post.top()=="-"){
      post.pop();
      a = stoi(mystack.top());
      mystack.pop();
      b = stoi(mystack.top());
      mystack.pop();
      mystack.push(to_string(b-a));
  }
  else if (post.top()=="*"){
    post.pop();
    a = stoi(mystack.top());
    mystack.pop();
    b = stoi(mystack.top());
    mystack.pop();
    mystack.push(to_string(b*a));
}
else if (post.top()=="/"){
  post.pop();
  a = stoi(mystack.top());
  mystack.pop();
  b = stoi(mystack.top());
  mystack.pop();
  mystack.push(to_string(b/a));
}
else {

  mystack.push(post.top());
post.pop();
}
}
return mystack.top();
}
//OPERATER IS +-* OPERAND IS 123

//----------------------------------------------------------------
int main(int argc, char ** argv)
{
    string line;
    cout << "Expression: ";
    while ( getline(cin, line) )
    {
        // skip empty line
        if (line.length() == 0)
            continue;

        stack<string> postfix;

        generateRPN(line, postfix);

        cout << "Answer: " << evaluateRPN(postfix) << endl;
        line.clear();
        cout << "Expression: ";
    }
    return 0;
}
