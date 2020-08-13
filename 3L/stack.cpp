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
stack::stack(stack&&s){
  _capacity = s._capacity;
  _tos = s._tos;
  _arr = s._arr;
  s._capacity = 0;
}

stack& stack::operator = (stack&& s){  //move assignment
  if (this == &s){
    return *this;
  }
  delete[]_arr;
  _capacity = s._capacity;
  _tos = s._tos;
  _arr = s._arr;
  s._arr = nullptr; s=_capacity = 0;
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
  throw FullStackException();
}
else {
  _arr[++_tos] = x;
}

}
stack::~stack(){
  delete []_arr;
}
