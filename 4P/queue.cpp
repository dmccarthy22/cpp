/** CS515 Assignment 4P File: queue.cpp
Name: Dan McCarthy
Section: 1
Date: 10/3/18
Collaboration Declaration: Collaborated with Paul Ackels
*/
#include "queue.h"


queue::queue(int capacity) : _capacity(capacity), _front(0), _size(0)
{
  _arr = new TYPE[_capacity]{0};


}

queue::queue(const queue& q)
:_capacity(q._capacity), _front(q._front), _size(q._size)
{ //copy constructor
  _arr =new int[_capacity];
    for (int i = 0; i < _capacity; i++){
      _arr[i] = q._arr[i];
}
}
queue& queue::operator = (const queue& q)
{ //assignment
  if (this == &q)
  return *this;
  delete[]_arr;
  _capacity = q._capacity;
  _front = q._front;
  _size = q._size;
  if (_capacity >0){
    _arr = new int [_capacity];
    for (int i = 0; i < _capacity; i++){
      _arr[i] = q._arr[i];
    }
  }
  return *this;
}
queue::~queue(){
  delete[] _arr;
}




void queue::enqueue(int data){
  int counter = 0;
  //int k = _front;

if (_size==_capacity){

  int *newArray = new int[_capacity*2]{};
  for (int i = 0; i < _capacity; i++){
    newArray[i] = _arr[i];
    counter++;
  }
  newArray[counter] = data;
  _capacity= _capacity*2;
  delete []_arr;
  _arr = newArray;
//  _front = _front+1;
  _size++;

}
else {
  _arr[_size] = data;
  _size++;
  //_front++;

}


}

TYPE queue::dequeue(){
  TYPE deq = _arr[_front];
  if(size()!=0){
    _arr[_front]=0;
    _size--;
    _front++;
    return deq;
  }
  else
  throw EmptyQueueException();
}

void queue::dump(ostream &os){
  for(int i=_front; i<=_size-1; i++){
    os <<_arr[i]<< " ";
  }
  os<<endl;
}

int queue::capacity(){
  return _capacity;
}
TYPE& queue::front(){
  return _arr[_front];
}




int queue::size(){
    return _size;
}

bool queue::empty(){
    return _size ==0;
}

/*
int main(){
queue m(3);

m.enqueue(9);


m.enqueue(10);

m.enqueue(11);
m.enqueue(12);
cout << m.dequeue() << endl;
queue n = m;
cout << n.size() << endl;
//cout << m.front() << endl;
//cout <<m.size() << endl;
//cout << m.capacity()<< endl;
//cout << m.capacity() << endl;
//cout << m.dequeue() << endl;
//m.dequeue();
//cout << m.size() << endl;;

//cout << m[m.front()];


}
*/
