#include "set.h"
#include <queue>
/* CS515 Lab 7
 File: set.cpp
 Name: Dan McCarthy
 Section: 4
 Collaboration Declaration:
 I collaborated with Nick Moreschi
 */


Set::Set():_size(0){
    // create a dummy root node
    _root = new Elem;
    _root->info = numeric_limits<int>::max();
    _root->left = _root;  // empty tree
    _root->right = 0;
    _root->rightThread = false;
}

Set::~Set(){
    if (_root->left != _root)  // not an empty tree
        destructCode(_root->left);
    delete _root;
}

void Set::destructCode(Elem *& p){
    if (p -> left) {
        destructCode(p -> left);
    }
    if (!p -> rightThread) {
        destructCode(p -> right);
    }
    delete p;
}


// returns true if the new node is inserted, otherwise false
bool Set::insert(ELEMENT_TYPE v){
    if (insert(_root->left, v, _root)){
        _size++;
        return true;
    }
    return false;
}

// insert helper method
// returns true if the new node is inserted, otherwise false
bool Set::insert(Elem *&cur, const ELEMENT_TYPE &value, Elem *lastLeft){
    if (cur == _root || cur == 0) {
        cur = new Elem;
        cur->info = value;
        cur->left = 0;
        cur->right = lastLeft;
        cur->rightThread = true;
        return true;
    }
    
    if (value == cur->info){
        return false;
    }
    // insert at left
    if (value < cur->info)
        return insert( cur->left, value, cur);
    
    // insert at right
    if (!cur->rightThread){
        return insert(cur->right, value, lastLeft);
    } else {  // current's right is a thread; add a new node
        cur->rightThread = false;
        cur->right = new Elem;
        cur->right->info = value;
        cur->right->left = 0;
        cur->right->right = lastLeft;
        cur->right->rightThread = true;
        return true;
    }
}

// print out tree elements in depth first in order
void Set::depthFirstInOrder(){
   Elem *cur = _root -> left;
   while (cur != _root) {
       while (cur -> left) {
           cur = cur -> left;
       }

       cout << cur -> info << " ";

       while (cur -> rightThread && cur -> right != _root) {
           cur = cur -> right;
           cout << cur -> info << " ";
       }

       cur = cur -> right;
   }
}

void Set::breadthFirst(){
    Elem *p = _root -> left;
    queue<Elem*> q;
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        cout << p -> info << " ";
        q.pop();
        if (p -> left) {
            q.push(p -> left);
        }
        if  (p -> right && !p -> rightThread) {
            q.push(p -> right);
        }
    }
}

int Set::size() const{
    return _size;
}

// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
void Set::printTree(ostream& out, int level, Elem *p){
    int i;
    if (p) {
        if (p->right && !p->rightThread)
            printTree(out, level+1,p->right);
        for(i=0;i<level;i++)
            out << "\t";
        out << p->info << '\n';
        printTree(out, level+1,p->left);
    }
}

// outputs information in tree in inorder traversal order
ostream& Set::dump(ostream &out){
    if ( _root == _root->left) // tree empty
        return out;
    printTree(out, 0, _root->left);   // print tree structure
    return out; 
}


// outputs using overloaded << operator
ostream& operator << (ostream &s, Set &v){
    v.dump(s);
    return s;
}

