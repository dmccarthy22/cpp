/** CS515 Assignment 6L File: PQueue0.cpp
Name: Dan McCarthy
Section: 1
Date: 10/3/18
Collaboration: Collaborated with Cameron Scott and Nick Moreschi
*/

#include <iostream>

template <class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue()
{
    for (int i = 1; i < MAX_SIZE + 1; i++)
    { 
        _array[i] = 0;
    }
    _size = 0;
}
template <class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue(T *items, int size)
{
    for (int i = 1; i < MAX_SIZE + 1; i++)
    { 
        _array[i] = items[i - 1];
    }
    _size = size;
    buildHeap();
}
template <class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::insert(T item)
{
    _size++;
    if (_size != 0)
    {
        _array[_size] = item;
        moveUp();
    }
    else
    {
        _array[1] = item;
    }

    return;
}
template <class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::buildHeap()
{
    for (int i = _size / 2; i > 0; i--)
    {
        moveDown(i);
    }
    return;
}
template <class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveDown(int raw_index)
{
    int i = raw_index;
    int count = 0;
    while (!(i > _size / 2 + 1) and i <= _size)
    {
        

        count++;
        int left_child_index = 0, right_child_index = 0;
        bool left_child_valid = false;
        bool right_child_valid = false;
        left_child_index = 2 * i;
        if (_array[i] >= _array[left_child_index])
        {
            left_child_valid = true;
        }

        if ((2 * i) + 1 <= _size)
        {
            right_child_index = (2 * i) + 1;

            if (_array[i] >= _array[right_child_index])
            {
                right_child_valid = true;
            }
        }
        if (left_child_valid and right_child_valid)
        {
            if (_array[left_child_index] >= _array[right_child_index])
            {

                int temp = _array[i];
                _array[i] = _array[right_child_index];
                _array[right_child_index] = temp;
                i = right_child_index;
                continue;
            }
            else
            {
                int temp = _array[i];
                _array[i] = _array[left_child_index];
                _array[left_child_index] = temp;
                i = left_child_index;
                continue;
            }
        }
        else
        {
            if (left_child_valid)
            {
                int temp = _array[i];
                _array[i] = _array[left_child_index];
                _array[left_child_index] = temp;
                i = left_child_index;
                continue;
            }
            else if (right_child_valid)
            {
                int temp = _array[i];
                _array[i] = _array[right_child_index];
                _array[right_child_index] = temp;
                i = right_child_index;
                continue;
            }
            else
            {
                break;
            }
        }
    };
}
template <class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveUp()
{
    int i = _size;

    while (_array[i / 2] > _array[i] and i / 2 > 0)
    {
        int temp = _array[i];
        _array[i] = _array[i / 2];
        _array[i / 2] = temp;
        i = i / 2;
    }
}
template <class T, int MAX_SIZE>
T PQueue<T, MAX_SIZE>::findMin()
{
    return _array[1];
}
template <class T, int MAX_SIZE>
void PQueue<T, MAX_SIZE>::deleteMin()
{
    _array[1] = _array[_size];
    moveDown(1);
    _size--;
    return;
}
template <class T, int MAX_SIZE>
bool PQueue<T, MAX_SIZE>::isEmpty()
{
    if (_size == 0)
        return true;
    return false;
}
template <class T, int MAX_SIZE>
int PQueue<T, MAX_SIZE>::size()
{
    return _size;
}
