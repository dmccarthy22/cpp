/** CS515 Assignment 6P File: set.cpp
Name: Dan McCarthy
Section: 1
Date: 10/17/18
*/

#include <iostream>
#include "set.h"

using namespace std;

Set::Set()
{
    _head = new Elem;

    _tail = new Elem;
    _head->next = _tail;
    _tail->prev = _head;
    
    _size = 0;
}
void Set::copyCode(const Set &s)
{
    _size = s._size;
    _head = new Elem;
    _tail = new Elem;
    Elem *src = s._head->next;
    Elem *temp = _head;
    while (src != s._tail)
    {
        Elem *hold = new Elem;
        hold->info = src->info;
        hold->prev = temp;
        temp->next = hold;
        temp = temp->next;
        src = src->next;
    }
    temp->next = _tail;
    _tail->prev = temp;
}
void Set::destructCode()
{
    Elem *tmp = _head;
    while (tmp!=_tail)
    {
        tmp = tmp->next;
        delete tmp->prev;
    }
    delete tmp;
}
Set::~Set()
{
    destructCode();
}

Set::Set(const Set &rhs)
{
    copyCode(rhs);
}

Set& Set::operator=(const Set &rhs){
    if (&rhs == this)
    {
        return *this;
    }
    _size = rhs._size;
    Elem *temp = _head;
    while (temp != _tail)
    {
        temp = temp->next;
        delete temp->prev;
    }
    delete temp;
    _head = new Elem;
    _tail = new Elem;
    temp = _head;
    Elem *src = rhs._head->next;
    while (src != rhs._tail)
    {
        Elem *hold = new Elem;
        hold->info = src->info;
        hold->prev = temp;
        temp->next = hold;
        temp = temp->next;
        src = src->next;
    }
    temp->next = _tail;
    _tail->prev = temp;
    return *this;
}

void Set::insert(ELEMENT_TYPE num){
    if(find(num)==end()){
        Elem *e = new Elem;
        e->info = num;
        if(_size==0){
            _tail->prev = e;
            _head->next = e;
            e->prev = _head;
            e->next = _tail;
            _size++;
            
        } else {
            Elem *c = _head->next;
          
            while(c != _tail && c->info <num){
                c = c->next;
            }
            e->prev = c->prev;
            e->next = c;
            c->prev->next = e;
            c->prev = e;
            _size++;
        }
    }

    
}
void Set::erase(ELEMENT_TYPE e){
    if (find(e)!= end()){
        Elem *c = _head->next;
        while(c->info != e){
            c = c->next;
        }
        c->prev->next = c->next;
        c->next->prev = c->prev;
        delete c;
        _size--;
    }
}
void Set::clear(){
    Elem *curr = _head->next;
    while(curr !=_tail){
        curr = curr->next;
        delete curr->prev;
        
    }
    
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
}
int Set::size() const{
    return _size;
}



Set::Iterator::Iterator()
{
    _cur = nullptr;

}
Set::Iterator::Iterator(Elem *cur)
{
    _cur = cur;

}

ELEMENT_TYPE& Set::Iterator::operator*()
{
   return _cur->info;
}
Set::Iterator Set::Iterator::operator++(int j)
{
    _cur = _cur->next;
    return *this;

}

Set::Iterator Set::Iterator::operator--(int j)
{
    _cur = _cur->prev;
    return *this;
}

bool Set::Iterator::operator==(Iterator it)const
{
    return it._cur->info ==_cur->info;

}
bool Set::Iterator::operator!=(Iterator it) const
{
    return it._cur != _cur;
}

Set::Reverse_Iterator::Reverse_Iterator()
{
    _cur = nullptr;
}

Set::Reverse_Iterator::Reverse_Iterator(Elem *cur)
{
    _cur = cur;
}

ELEMENT_TYPE &Set::Reverse_Iterator::operator*()
{
    return _cur->info;
}

Set::Reverse_Iterator Set::Reverse_Iterator::operator++(int j)
{
    _cur = _cur->prev;
    return *this;

}
Set::Reverse_Iterator Set::Reverse_Iterator::operator--(int j)
{
    _cur = _cur->next;
    return *this;
}

bool Set::Reverse_Iterator::operator==(Reverse_Iterator it) const
{
    return it._cur->info == _cur->info;
}

bool Set::Reverse_Iterator::operator!=(Reverse_Iterator it) const
{
    return it._cur->info != _cur->info;
}

Set::Iterator Set::find(ELEMENT_TYPE f)const
{
    
    Elem *curr = _head->next;
    while(curr != _tail){
        if (curr->info ==f){
            return Set::Iterator(curr);
        }
        curr = curr->next;
    }
    return end();
   
    
}

Set::Iterator Set::end() const{
   return Set::Iterator(_tail);

}
Set::Iterator Set::begin() const
{
    return Set::Iterator(_head->next);
}
Set::Reverse_Iterator Set::rend()const{
    return Set::Reverse_Iterator(_head);
}
Set::Reverse_Iterator Set::rbegin()const{
    return Set::Reverse_Iterator(_tail->prev);
}
ostream &operator<<(ostream & out, Set & s){
    Set::Iterator it = s.begin();
    while(it !=s.end()){
        out << *it << " ";
        it++;
    }
    return out;

}

ostream& Set::dump(ostream &out, const Set &v){
    Set::Iterator it = v.begin();
    while (it != v.end())
    {
        out << *it << " ";
        it++;
    }
    return out;
}
bool operator==(const Set& s1, const Set& s2){
    if (s1.size() != s2.size()){
        return false;
    } 
    Set::Iterator it1 = s1.begin();
    Set::Iterator it2 = s2.begin();
    while(it1!=s1.end()){
        if(*it1 != *it2){
            return false;
        }
        it1++;
        it2++;
        
    }
        

    
    return true;
}

Set operator|(const Set &s1, const Set &s2){
    Set n = s1;
   
    Set::Iterator it = s2.begin();
    while(it != s2.end()){
        n.insert(*it);
        it++;
    }
    return n;
    
  
}
Set operator&(const Set &s1, const Set &s2)
{
    Set n;
    Set::Iterator it1 = s2.begin();
    Set::Iterator it2 = s1.begin();
    while (it1 != s2.end()){
        while (it2 != s1.end()){
            if (*it1 == *it2){
                n.insert(*it1);
            }
            it2++;
        }
        it2=s1.begin();
        it1++;
    }
    return n;
}

Set operator-(const Set &x, const Set &y)
{ 
  Set s = x;
  Set::Iterator it = y.begin();
  while(it !=y.end()){
      s.erase(*it);
      it++;
  }
  return s;
}