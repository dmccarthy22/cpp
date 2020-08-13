/** CS515 Assignment 4P File: stack.cpp
Name: Dan McCarthy
Section: 1
Date: 10/3/18
Collaboration Declaration: Collaborated with Paul Ackels
*/
#include "stack.h"



stack::stack(int capacity) : _capacity(capacity), _tos(-1)
{
  _arr = new TYPE[_capacity]{0};
}

stack::stack(const stack& s) // copy
:_capacity(s._capacity), _tos(s._tos)
{
_arr =new int[_capacity];
  for (int i = 0; i < _capacity; i++){
    _arr[i] = s._arr[i];
  }
}
stack& stack::operator = (const stack& s)
{ //assignment
  if (this == &s)
  return *this;
  delete[]_arr;
  _capacity = s._capacity;
  _tos = s._tos;
  if (_capacity >0){
    _arr = new int [_capacity];
    for (int i = 0; i < _capacity; i++){
      _arr[i] = s._arr[i];
    }
  }
  return *this;
}




void stack::pop(){
if(empty()){
  throw EmptyStackException();
}
else {
  --_tos;
}
}
TYPE& stack::top(){
if (empty()){
  throw EmptyStackException();
}
else {
  return _arr[_tos];
}
}
bool stack::empty(){
return _tos == -1;
}
int stack::size(){
return _tos +1;
}
int stack::capacity(){
  return _capacity;
}
void stack::push(const TYPE x)
{

if (_tos == _capacity - 1){
  int counter =0;
int *newArray = new int[_capacity*2]{};
for (int i = 0; i < _capacity; i++){
  newArray[i] = _arr[i];
  counter++;
}
newArray[counter+1] = x;
delete []_arr;
_arr = newArray;
_capacity= _capacity*2;
_tos = _tos+1;

}
else {
  _arr[++_tos] = x;
}

}
stack::~stack(){
  delete []_arr;
}

void stack::dump(ostream &os){
for (int i = size()-1; i >= 0; i--){
  cout << _arr[i] << " ";
}
cout << endl;
}
