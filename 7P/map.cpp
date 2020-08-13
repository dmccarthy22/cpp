/**
 * Name: Dan McCarthy
 * Date: 12/15/19
 * File: map.cpp
 * Project: 7P/99P
 * Collaboration Declaration: Recieved assistance from TA's in the PAC
 */



// A non-generic Map ADT implemented with a BST data structure
// The BST is not-balanced and non-threaded
#include "map.h"

Map::Map(){
	// create a dummy root node and set up an empty tree
	_root = new Elem;
	_root->left = _root;  
	_root->right = 0;
	_size = 0;

}

// copy constructor
Map::Map(const Map &v){
	// if empty tree
	if (v._root == v._root->left){
		_root = new Elem;
		_root->left = _root;  // empty tree
		_root->right = 0;
		_size = 0;
	} else {
		_root = new Elem;
		_root->left = _root;
		_root->right = 0;
		copyCode(_root->left, v._root->left);
		_size = v._size;
	}
} 

// common copy code for deep copy a tree
void  Map::copyCode(Elem* &newRoot, Elem* origRoot){
	if (origRoot == 0)
		newRoot = 0;
	else{
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		copyCode(newRoot->left, origRoot->left);
		copyCode(newRoot->right, origRoot->right);
	}
}

Map&Map::operator=(const Map &rhs){
	if (this==&rhs){
		return *this;
	}
	destructCode(_root);
	if (rhs._root==rhs._root->left){
		_root = new Elem;
		_root->left = _root;
		_root->right = _root;

	}
	copyCode(_root->left, rhs._root);
	return *this;

}
Map::~Map(){
	if (_root->left != _root){
		destructCode(_root->left);
	}
	delete _root;

}
void Map::destructCode(Elem *& p){
	if (p->left != nullptr){
		destructCode(p->left);
	}
	if (p->right != nullptr){
		destructCode(p->right);
	}
	delete p;
}

	Map::Iterator Map::begin() const
{
	Elem *curr = new Elem;
	curr = _root->left;
	while (curr->left != nullptr){
		curr = curr->left;
	}
	return Map::Iterator(curr);
}
Map::Iterator Map::end()const
{
	return Map::Iterator(NULL);

}

Map::Elem &Map::Iterator::operator*(){
	
	return *_cur;
}
Map::Elem *Map::Iterator::operator-> ()
{
	return _cur;
}
bool Map::Iterator::operator==(Iterator it)const{
	return _cur == it._cur;

}
bool Map::Iterator::operator!=(Iterator it)const
{

	return _cur != it._cur;
}
VALUE_TYPE& Map::operator[](KEY_TYPE k){
	Map::Iterator it = find(k);

	if(it==Map::Iterator(NULL)){

		insert(k, "new string value");
	}


	
	Iterator it2 = find(k);

	
	return it2->data;

}

	Map::Iterator Map::find(KEY_TYPE key) const
{
	Elem *local = _root->left;

	
	while (local != nullptr)
	{

		if (key < local->key)
		{
			local = local->left;
		}
		else if (key > local->key)
		{
			local = local->right;
		}
		else if (key == local->key)
		{

			return Map::Iterator(local);
		}
	
	}
	

	return Map::Iterator(NULL);
}

bool Map::insert(KEY_TYPE k, VALUE_TYPE v){
	
	Elem *node = NULL;
	Elem *parent = _root;
	Elem *temp = _root->left;
	while (temp){
		if (k < temp->key){
			temp = temp->left;

		}
		else if (k > temp->key){
			temp = temp->right;
		}
		else if(k == temp->key){
			return false;
		}
	}

		node = new Elem;
		node->key = k;
		node->data = v;
		
	
		if(_size==0){
			
			_root->left = node;
			_size++;
			return true;

		}
		else if (_size==1){
			if (k > _root->left->key){
				_root->left->right = node;
				_size++;
				return true;

			} else {
				
				_root->left->left = node;
				_size++;
				return true;
			}
	}
	else if(_size >1){
		Elem *curr = new Elem;
		curr =_root->left;
		int lr = -1;
		while (curr!= NULL)
		{
			if(lr == -1){
				parent = parent->left;
			}
			else if (lr ==0){
				parent = parent->left;
			}
			else if (lr ==1){
				parent = parent->right;
			}
			if (k < curr->key){
				curr = curr->left;
				lr = 0;
			}
			else if (k > curr->key){
				curr = curr->right;
				lr = 1;
			}
		}
		if (k < parent->key){
			parent->left = node;
			_size++;
		}
		if (k > parent->key){
			parent->right = node;
			_size++;
		}
	}
	return true;
}

bool Map::erase(KEY_TYPE k){
    
    
    Iterator it= find(k);
    Elem *n = new Elem;
    n->data = it->data;
    n->key = it->key;
    n->left = it->left;
    n->right = it->right;

    
    if (n==0){
        return false;
    }
    
    
    Elem *cur = _root->left;
	Elem *parent = _root;
    while (cur->key != k && cur !=nullptr){ //to find parent
        parent = cur;
        if (k < cur->key){
            cur = cur->left;
        }
        else if (cur->key < k){
            cur = cur->right;
        } 
		else {
			return false;
		}
    }
	n = cur;

	if(n->right != 0 && n->left != 0){
		 Elem *nNext = n->right; //one to the right
		while(nNext->left != nullptr){ //all the way down to left
			nNext = nNext->left;
		}
		KEY_TYPE nNextKey = nNext->key;
		VALUE_TYPE nNextValue = nNext->data;
		// n->data = n->nextData;
		// n->key = nNext->key;
		erase(nNextKey); //recursive
		//_size--;
		n->data = nNextValue;
		n->key = nNextKey;
		return true;

	}
    
    
    else if (n->right == 0 && n->left == 0){ //leaf
        if (parent->right == n){
            parent->right = 0;
        }
        else if (n!= _root->left){
            parent->right = 0;
        } else {
            parent->left = _root;
        }
		delete n;
    
        _size--;
        
        return true;
    
    }
    
    else if (n->right == 0 && n->left != 0){ //only left
        if(parent->right == n){
            parent->right = n->left;
        } else {
            parent->left = n->left;
        }
		delete n;
        _size--;
        
        return true;
    }
    
    else {//only right
        if (parent->left == n){
            parent->left = n->right;
        }
        else{
			parent->right = n->right;
        }
        delete n;
        _size--;
        return true;
    }
    
}





// 
//  Do Not Modify Below Here
//
//
// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
void Map::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		printTree(out, level+1, p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1, p->left);
	}
}

// outputs information in tree
ostream& Map::dump(ostream& out) const{
	if ( _root == _root->left) { // tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}

// outputs using overloaded << operator
ostream& operator<< (ostream& out, const Map& v){
	v.dump(out);
	return out;
}


/*
 Map::Iterator it = find(k);
 Elem  *n =new Elem;
 n->data = it->data;
 n->key = it->key;
 n->left = it->left;
 n->right = it->right;
 Elem *curr = _root->left;
 Elem *parent = _root;
 if (curr == _root){
 return false;
 }
 else if (_size == 0)
 {
 return false;
 }
 else{
 if (_size == 1){
 delete _root->left;
 _size--;
 return true;
 }
 
 else {
 int lr = -1;
 while (curr->key != n->key)
 {
 if (lr == -1)
 {
 parent = parent->left;
 }
 else if (lr == 0)
 {
 parent = parent->left;
 }
 else if (lr == 1)
 {
 parent = parent->right;
 }
 if (k < curr->key)
 {
 curr = curr->left;
 lr = 0;
 }
 else if (k > curr->key)
 {
 curr = curr->right;
 lr = 1;
 }
 }
 if (n->key == _root->left->key){
 Elem *ios = _root->left->right;
 while (ios->left != NULL){
 ios = ios ->left;
 }
 _root->left = NULL;
 delete parent->left;
 _root->left = ios;
 _size--;
 return true;
 }
 else if (n->left == NULL and n->right == NULL){
 
 if (n->key == parent->right->key){
 delete parent->right;
 delete n;
 parent->right = NULL;
 
 
 return true;
 }
 else {
 
 delete parent->left;
 parent->left = NULL;
 delete n;
 return true;
 }
 }
 else if (n->left != NULL && n->right == NULL){
 Elem *ios = new Elem;
 ios = n->left;
 parent->left = NULL;
 delete parent->left;
 parent->left = ios;
 delete ios;
 delete n;
 _size--;
 return true;
 }
 else if (n->left == NULL&& n->right != NULL){
 
 Elem *ios = n->right;
 while (ios->left !=NULL){
 ios = ios->left;
 }
 parent->left = NULL;
 parent->right = ios;
 //delete ios;
 delete n;
 _size--;
 return true;
 
 
 
 
 }
 else if (n->left != NULL && n->right != NULL){
 
 Elem *ios = n->right;
 while (ios->left != NULL){
 ios = ios->left;
 }
 if (n->key == parent->left->key){
 
 parent->left = NULL;
 delete parent->left;
 parent->left = ios;
 parent->left->left = n->left;
 _size--;
 return true;
 }
 if (n->key == parent->right->key){
 parent->right = NULL;
 delete parent->right;
 parent->right = ios;
 _size--;
 return true;
 }
 
 
 
 }
 
 
 
 }
 }
 return true;
 
 
 
 
 */
