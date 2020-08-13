#include <iostream>
#include "set.h"

using namespace std;

Set::Set(){
  _head  = 0;

  _tail = 0;
  _size = 0;

}

void Set::copyCode(const Set & s){
  Elem *tmp = _head;
  Elem *sTmp = s._head;
  _size = s._size;
  _tail = s._tail;
  while(tmp->next != nullptr){
    sTmp->next = tmp ->next;
    sTmp->next->prev = sTmp;
    tmp = tmp->next;
    sTmp = sTmp ->next;
  }
}

void Set::destructCode(){
  Elem *tmp = _head;
  while(tmp->next != nullptr){
    Elem *sTmp = tmp -> next;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    tmp = sTmp;
  }
}

Set::~Set(){
  destructCode();
}

Set::Set(const Set &rhs){
  copyCode(rhs);
}

Set& Set::operator=(const Set &rhs){
  if(*this==rhs){
    return *this;
  }
  destructCode();
  _size = rhs._size;
  _head = rhs._head;
  _tail = rhs._tail;
  if(_size>0){
    copyCode(rhs);
  }
  return *this;
}

void Set::insert(ELEMENT_TYPE n){

  if (_size == 0){
Elem *b = new Elem;
b->info = n;
_head = b;

_head ->next = b;

_tail = b;
_tail->prev = b;
b->prev = _head;
b->next = _tail;

_head = 0;
_tail = 0;
} else {
  Elem *temp = new Elem;
  temp->info = -1;
  _head = temp;
  _tail = temp;
  Elem * curr = new Elem;
  curr = _head;
  while (curr!=_tail){
    if (curr->info < n){
      curr = curr->next;
    } else {
      break;
    }

  }
  Elem *q = new Elem;
  q->info = n;
  curr->next = q;
  q->next = _tail;
  _head->next = q;
  _tail->prev = q;
  _head =0;
  _tail = 0;


}

_size++;
}

void Set::erase(ELEMENT_TYPE n){
  Elem *tmp = _head;
  while(tmp->next != nullptr){
    if(tmp->info==n){
      tmp->prev->next = tmp ->next;
      tmp->next->prev = tmp ->prev;
      tmp->next = nullptr;
      tmp->prev = nullptr;
    }
    else{
      tmp = tmp->next;
    }
  }
}
void Set::clear(){
  Elem *tmp = _head;
  Elem *sTmp = tmp->next;
  while(tmp->next!=nullptr){
    tmp->prev = nullptr;
    tmp->next = nullptr;
    sTmp = tmp;
  }
}

int Set::size()const {
return _size;
}

bool Set::find(ELEMENT_TYPE n)const{
  _head->info = -1;

  Elem *tmp = _head;

  while (tmp->next!=nullptr) {
    if(tmp->info==n){
      return true;
    } else{
      tmp = tmp->next;
    }
  }

  return false;
}

ostream& Set::dump(ostream& out, const Set &v)const{
 Elem *tmp = v._head;
  while (tmp->next!=nullptr) {
  out <<tmp->info<< " ";
    tmp=tmp->next;
  }
  out<<endl;
return out;
}

bool operator==(const Set& s1, const Set& s2){
  Set::Elem *tmp1, *tmp2;
  tmp1=s1._head;
  tmp2=s2._head;
  while(tmp1->next!=nullptr){
    if(tmp1->info!=tmp2->info){
      return false;
    }
    tmp1=tmp1->next;
    tmp2=tmp2->next;
  }
  return true;

}

ostream& operator<< (ostream& out, const Set& s){
  Set::Elem *tmp;
  tmp=s._head;
  cout << "m" << endl;


  while (tmp->next!=nullptr) {

  cout <<tmp->info<< " ";

  tmp=tmp->next;
  }
  out<<endl;
return out;
}



/*int main (){
Set *m = new Set();
m->insert(5);
m->insert(6);
m->insert(7);
m->erase(6);




}
*/
