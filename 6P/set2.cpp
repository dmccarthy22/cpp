#include "set.h"
#include <iostream>
using namespace std;

Set::Set()
{
    _size = 0;
    _head = new Elem;
    _tail = new Elem;
    _head->next = _tail;
    _head->prev = 0;
    _tail->next = 0;
    _tail->prev = _head;
}
Set::Set(const Set &source)
{
    _size = source._size;
    _head = new Elem;
    _tail = new Elem;
    Elem *src = source._head->next;
    Elem *temp = _head;
    while (src != source._tail)
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
Set::~Set()
{
    Elem *temp = _head;
    while (temp != _tail)
    {
        temp = temp->next;
        delete temp->prev;
    }
    delete temp;
}
Set &Set::operator=(const Set &source)
{
    if (&source == this)
    {
        return *this;
    }
    _size = source._size;
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
    Elem *src = source._head->next;
    while (src != source._tail)
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
void Set::insert(ELEMENT_TYPE x)
{
    Elem *hold = new Elem;
    hold->info = x;
    Elem *t = _head->next;
    while (t != _tail)
    {
        if (t->info == x)
        {
            return;
        }
        t = t->next;
    }
    t = _head;
    while (t)
    {
        if (t->info > x || t == _tail)
        {
            Elem *pre = t->prev;
            pre->next = hold;
            hold->prev = pre;
            hold->next = t;
            t->prev = hold;
            _size++;
            return;
        }
        t = t->next;
    }
}
//should work might be a double delete error
void Set::erase(ELEMENT_TYPE x)
{
    Elem *temp = _head->next;
    while (temp != _tail)
    {
        if (temp->info == x)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            _size--;
            return;
        }
        temp = temp->next;
    }
}
//should work
void Set::clear()
{
    Elem *temp = _head->next;
    while (temp != _tail)
    {
        temp = temp->next;
        delete temp->prev;
    }
    _head->next = _tail;
    _tail->prev = _head;
    _size = 0;
}
int Set::size() const
{
    return _size;
}

Set::Iterator Set::find(ELEMENT_TYPE x) const
{
    Elem *hold = _head->next;
    while (hold != _tail)
    {
        if (hold->info == x)
        {
            Set::Iterator it = Set::Iterator(hold);
            return it;
        }
        hold = hold->next;
    }
    return end();
}

Set::Iterator Set::begin() const
{
    Set::Iterator it = Iterator(_head->next);
    return it;
}

Set::Iterator Set::end() const
{
    Set::Iterator it = Iterator(_tail);
    return it;
}

Set::Reverse_Iterator Set::rbegin() const
{
    Set::Reverse_Iterator it = Reverse_Iterator(_tail->prev);
    return it;
}

Set::Reverse_Iterator Set::rend() const
{
    Set::Reverse_Iterator it = Reverse_Iterator(_head);
    return it;
}

ostream &operator<<(ostream &os, Set &source)
{
    Set::Iterator it = source.begin();
    while (it != source.end())
    {
        os << *it << " ";
        it++;
    }
    return os;
}

Set::Iterator::Iterator()
{
    _cur = nullptr;
}

Set::Iterator::Iterator(Elem *cur)
{
    _cur = cur;
}

ELEMENT_TYPE &Set::Iterator::operator*()
{
    return _cur->info;
}

Set::Iterator Set::Iterator::operator++(int x)
{
    _cur = _cur->next;
    return *this;
}

Set::Iterator Set::Iterator::operator--(int x)
{
    _cur = _cur->prev;
    return *this;
}

bool Set::Iterator::operator==(Iterator it) const
{
    if (_cur == it._cur)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Set::Iterator::operator!=(Iterator it) const
{
    if (_cur == it._cur)
    {
        return false;
    }
    else
    {
        return true;
    }
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

Set::Reverse_Iterator Set::Reverse_Iterator::operator++(int x)
{
    _cur = _cur->prev;
    return *this;
}

Set::Reverse_Iterator Set::Reverse_Iterator::operator--(int x)
{
    _cur = _cur->next;
    return *this;
}

bool Set::Reverse_Iterator::operator==(Reverse_Iterator it) const
{
    if (_cur == it._cur)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Set::Reverse_Iterator::operator!=(Reverse_Iterator it) const
{
    if (_cur == it._cur)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Set operator&(const Set &s1, const Set &s2)
{
    Set s3;
    Set::Iterator it1 = s1.begin();
    Set::Iterator it2 = s2.begin();
    while (it1 != s1.end())
    {
        while (it2 != s2.end())
        {
            if (*it1 == *it2)
            {
                s3.insert(*it1);
            }
            it2++;
        }
        it2 = s2.begin();
        it1++;
    }
    return s3;
}
Set operator|(const Set &s1, const Set &s2)
{
    Set s3 = s1;
    Set::Iterator it2 = s2.begin();
    while (it2 != s2.end())
    {
        s3.insert(*it2);
        it2++;
    }
    return s3;
}

Set operator-(const Set &s1, const Set &s2)
{
    Set s3 = s1;
    Set::Iterator it2 = s2.begin();
    while (it2 != s2.end())
    {
        s3.erase(*it2);
        it2++;
    }
    return s3;
}

bool operator==(const Set &s1, const Set &s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    Set::Iterator it1 = s1.begin();
    Set::Iterator it2 = s2.begin();
    while (it1 != s1.end())
    {
        if (*it1 != *it2)
        {
            return false;
        }
        it1++;
        it2++;
    }
    return true;
}
