#include "queue.h"
#include <exception>

// singly linked list implementation of queue
// empty queue is represented by null front and rear pointers

queue::queue()
: _size(0)
{
_front = NULL;
_rear = NULL;
}

queue::~queue(){
}

// copy constructor
queue::queue(const queue &v) //KEEP CALLING ENQUEUE
  : _size(v._size), _front(v._front), _rear(v._rear)
{

}

// assignment operator
queue& queue::operator=(const queue &rhs){
    return *this;
}

void queue::enqueue(const TYPE data){
node *n = new node(data, nullptr);
_rear = n;
_size++;




}

TYPE queue::dequeue(){
if (this->empty()){
  throw EmptyQueueException();
  //return NULL;
}
else {

node *n = new node(_front->data, _front->next);

_front = n->next;
delete n;
_size--;
TYPE val = _front->data;
	return val;
}
}
void queue::dump(ostream &os){
}

int queue::size(){
    return _size;
}

bool queue::empty(){
    if(_front == NULL && _rear == NULL){
      return true;
    }
    return false;
}
