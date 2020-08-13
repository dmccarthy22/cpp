#include <map> // helper container for thread copying

template <typename KEY, typename T>
Map<KEY, T>::Map()
{
	// create a dummy root node
	_root = new Elem;
	_root->left = _root; // empty tree
	_root->right = 0;
	_root->rightThread = false;
	_size = 0;
	
}
// copy constructor
template <typename KEY, typename T>
Map<KEY, T>::Map(const Map<KEY, T> &v)
{
	// if empty tree
	if (v._root == v._root->left)
	{
		_root = new Elem;
		_root->left = _root; // empty tree
		_root->right = 0;
		_size = 0;
	}
	else
	{
		_root = new Elem;
		_root->left = _root;
		_root->right = 0;
		copyCode(_root->left, v._root->left); // to deep copy the tree without dummy nodes
		copyThread(_root, v._root);			  // to copy the threading; must pass dummy nodes to complete the threads
		_size = v._size;
	}
}

template <typename KEY, typename T>
void Map<KEY, T>::addToMap(Elem *root, map<KEY, Elem *> &keyElemMap)
{
	if (root)
	{
		keyElemMap[root->key] = root;
		addToMap(root->left, keyElemMap);
		if (!root->rightThread)
			addToMap(root->right, keyElemMap);
	}
}

// output the structure of tree. The tree is output as "lying down"
// output each node's key, value and its tree height 
template <typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		if (p->right && !p->rightThread)
			printTree(out, level+1,p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << "(" << p->height << ")" << '\n';
		printTree(out, level+1,p->left);
	}
}

// common copy code for thread copying
template <typename KEY, typename T>
void Map<KEY, T>::copyThread(Elem *&newRoot, Elem *origRoot)
{
	// construct the key-element map for new and orig tree
	map<KEY, Elem *> newKeyElemMap;
	map<KEY, Elem *> origKeyElemMap;
	addToMap(newRoot->left, newKeyElemMap);
	addToMap(origRoot->left, origKeyElemMap);

	// start at the last element in the tree, which threads to root
	typename std::map<KEY, Elem *>::reverse_iterator it = origKeyElemMap.rbegin();
	newKeyElemMap[it->first]->rightThread = true;
	newKeyElemMap[it->first]->right = newRoot;

	// then thread the rest of the tree backwardly
	it++;
	while (it != origKeyElemMap.rend())
	{
		if (it->second->rightThread)
		{
			newKeyElemMap[it->first]->rightThread = true;
			newKeyElemMap[it->first]->right = newKeyElemMap[origKeyElemMap[it->first]->right->key];
		}
		it++;
	}
}
template <typename KEY, typename T>
void Map<KEY, T>::copyCode(Elem *&newRoot, Elem *origRoot)
{
	if (origRoot == 0)
		newRoot = 0;
	else
	{
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		newRoot->rightThread = origRoot->rightThread;
		copyCode(newRoot->left, origRoot->left);
		if (!origRoot->rightThread)
			copyCode(newRoot->right, origRoot->right);
	}
}

template <typename KEY, typename T>
Map<KEY, T>::~Map()
{
	if (_root->left != _root)
	{
		destructCode(_root->left);
	}
	delete _root;
}

template <typename KEY, typename T>
void Map<KEY, T>::destructCode(Elem *&p)
{
	if (p->left != nullptr)
	{
		destructCode(p->left);
	}
	if (!p->rightThread)
	{
		destructCode(p->right);
	}
	delete p;
}

template <typename KEY, typename T>
bool Map<KEY, T>::insert(Elem *&cur, const KEY &key, const T &data, Elem *lastLeft)
{
	if (cur == _root || cur == 0)
	{
		cur = new Elem;
		cur->key = key;
		cur->data = data;
		cur->right = lastLeft;
		cur->rightThread = true;
		cur->left = 0;

		return true;
	}
	if (key == cur->key)
	{
		return false;
	}
	if (key < cur->key)
	{
		return insert(cur->left, key, data, cur);
	}
	if (!cur->rightThread)
	{
		return insert(cur->right, key, data, lastLeft);
	}
	else
	{
		cur->rightThread = false;
		cur->right = new Elem;
		cur->right->data = data;
		cur->right->key = key;
		cur->right->left = 0;
		cur->right->right = lastLeft;
		cur->right->rightThread = true;
		//return true;

		
	}
	 
	if (height(cur->left) - height(cur->right) == 2)
	{							  // calculate load factor
		if (key < cur->left->key) // outside case
			rotateRight(cur);
		else // inside case
			doubleRotateRight(cur);
	}
	cur->height = max(height(cur->left), height(cur->right)) + 1; // update height

	if (height(cur->left) - height(cur->right) == -2)
	{							   // calculate load factor
		if (key > cur->right->key) // outside case
			rotateLeft(cur);
		else // inside case
			doubleRotateLeft(cur);
	}
	

	return true;
}
template <typename KEY, typename T>
bool Map<KEY, T>::insert(KEY key, T data)
{
	if (insert(_root->left, key, data, _root))
	{
		_size++;
		return true;
	}
	return false;
}

template <typename KEY, typename T>
int Map<KEY, T>::height(Elem *node)
{
	return node == 0 ? -1 : node->height;
}

template <typename KEY, typename T>
T &Map<KEY, T>::operator[](KEY key)
{
	T h;
	Iterator it = find(key);

	if (it == end())
	{
		insert(key, h);
		return find(key)->data;
	}
	return it->data;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Map &Map<KEY, T>::operator=(const Map &rhs)
{
	if (&rhs == this)
	{
		return *this;
	}
	if (_root->left != _root)
	{
		destructCode(_root->left);
	}

	_size = rhs._size;

	if (_size >= 1)
	{
		copyCode(_root->left, rhs._root->left);
		copyThread(_root, rhs._root);
	}
	return *this;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY key) const
{
	Elem *cur = _root->left;
	while (cur)
	{
		if (cur->key == key)
		{
			return Iterator(cur);
		}
		else if (cur->key < key)
		{
			if (cur->rightThread)
			{
				break;
			}
			else
			{
				cur = cur->right;
			}
		}
		else
		{
			cur = cur->left;
		}
	}
	return end();
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::begin() const
{ // return the left most (smallest) tree node
	Elem *el = _root;
	while (el->left != nullptr)
	{
		if (el->left != el)
		{
			el = el->left;
		}
		else
		{
			break;
		}
	}

return Map::Iterator(el);
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::end() const
{ // return the dummy root node
	return Iterator(_root);
	}

	template <typename KEY, typename T>
	typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int num)
	{
		Iterator r = *this;
		if (_cur->rightThread)
		{
			if (_cur->right)
			{
				_cur = _cur->right;
			}
		}
		else
		{
			if (_cur->right)
			{
				_cur = _cur->right;
			}
			while (_cur->left)
			{
				_cur = _cur->left;
			}
		}

		return r;
	}
	template <typename KEY, typename T>
	typename Map<KEY, T>::Elem &Map<KEY, T>::Iterator::operator*()
	{
		return *_cur;
	}

	template <typename KEY, typename T>
	typename Map<KEY, T>::Elem *Map<KEY, T>::Iterator::operator->()
	{
		return _cur;
	}

	template <typename KEY, typename T>
	int Map<KEY, T>::size() const
	{
		return _size;
	}

	template <typename KEY, typename T>
	bool Map<KEY, T>::Iterator::operator==(Iterator it)
	{
		return _cur == it._cur;
	}
	template <typename KEY, typename T>
	bool Map<KEY, T>::Iterator::operator!=(Iterator it)
	{
		return _cur != it._cur;
	}

	template <typename KEY, typename T>
	void Map<KEY, T>::rotateRight(Elem * &node)
	{
		Elem *beta = node->left;
		node->left = beta->right;
		beta->right = node;
		node->height = max(height(node->left), height(node->right)) + 1;
		beta->height = max(height(beta->left), height(beta->right)) + 1;
		node = beta;
	}

	template <typename KEY, typename T>
	void Map<KEY, T>::rotateLeft(Elem * &node)
	{
		Elem *alpha = node->right;
		node->right = alpha->left;
		alpha->left = node;
		node->height = max(height(node->left), height(node->right)) + 1;
		alpha->height = max(height(alpha->left), height(alpha->right)) + 1;
		node = alpha;



	}
	// double right rotation
	template <typename KEY, typename T>
	void Map<KEY, T>::doubleRotateRight(Elem * &node)
	{

		rotateLeft(node->left);
		rotateRight(node);
	}

	// double left rotation
	template <typename KEY, typename T>
	void Map<KEY, T>::doubleRotateLeft(Elem * &node)
	{

		rotateRight(node->right);
		rotateLeft(node);
	}

	// outputs information in tree in inorder traversal order
	template <typename KEY, typename T>
	ostream &Map<KEY, T>::dump(ostream & out) const
	{
		if (_root == _root->left)
		{ // tree empty
			return out;
		}
		printTree(out, 0, _root->left); // print tree structure
		return out;
	}

	// outputs using overloaded << operator
	template <typename KEY, typename T>
	ostream &operator<<(ostream &out, const Map<KEY, T> &v)
	{
		v.dump(out);
		return out;
	}

	// if (!cur->rightThread && cur->left)
	// {
	// 	bf = cur->left->height + cur->right->height;
	// }
	// else if (cur->left && cur->righThread)
	// {
	// 	bf = cur->left;
	// }
	// else if (cur->left == nullptr && !cur->rightThread)
	// {
	// 	bf = 0 - cur->right;
	// }
	// else
	// {
	// 	bf = 0;
	// }