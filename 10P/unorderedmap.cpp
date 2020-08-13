/* CS515 Assignment 10
File: unorderedmap.cpp
Name: Dan McCarthy
Section: 4
Collaboration Declaration:
          I received assistance from TA's in the PAC
*/
// Below are the stubs for SOME methods
// Make sure all methods in unorderedmap.h are implemented

template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(){
	tablesize = 101;
	entrysize = 0;
	array = new Entry *[tablesize]{};
	Entry *end = nullptr;
}
template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::UnorderedMap(const UnorderedMap &rhs){
	tablesize = rhs.size;
	entrysize = rhs.entrysize;
	array = new Entry *[tablesize];
	for (int i = 0; i < tablesize; i++){
		array[i] = rhs.array[i];
	}
	
}
template <typename KEY, typename T, typename H>
typename UnorderedMap<KEY, T, H>::UnorderedMap& UnorderedMap<KEY, T, H>::operator=(const UnorderedMap& rhs){
	if (this == rhs) {
		return *this;
	}
	tablesize = rhs.tablesize;
	entrysize = rhs.entrysize;
	for (int i = 0; i < tablesize; i++){
		array[i] = rhs.array[i];
	}
	return *this;

}



template <typename KEY, typename T, typename H>
UnorderedMap<KEY, T, H>::~UnorderedMap(){
	Entry *temp;
	Entry *prev;
	for (int i =0; i < tablesize; i++){
		if (array[i]!=NULL){
			temp = array[i];
			while (temp!= nullptr)
			{
				prev = temp;
				temp = temp->next;
				delete prev;
			}
			
	}
	else {
		delete array[i];

	}
	}
	delete [] array;

}

template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::insert(const KEY & newkey, const T & data){
	std::size_t index = H()(newkey); 
	index = index % tablesize;
	if (entrysize >= tablesize / 2)
	{
		rehash();
	}

	//index = 96;
	if (array[index] == NULL){

		Entry *ent = new Entry(newkey, data);
		array[index] = ent;
		array[index]->next = nullptr;
		//entrysize++;
		
	} else {
		Entry *temp = array[index];
		while (temp != NULL){
			if (temp->key == newkey){
				return false;
			} else {
				temp = temp->next;
			}

		}
		Entry * ent = new Entry(newkey, data);
		ent->next = array[index];
		array[index] = ent;
		
	}
	entrysize++;
	return true;
}
template <typename KEY, typename T, typename H>
bool UnorderedMap<KEY, T, H>::erase(const KEY &k)
{
	if (find(k)==end()){
		return false;
	} else {
	std::size_t index = H()(k);
	index = index % tablesize;
	Entry * parent = nullptr;
	Entry * entry = array[index];
	while (entry !=nullptr && entry->key != k){
		parent = entry;
		entry = entry->next;
	}
	if (parent == nullptr){
		array[index] = entry->next;
	} else {
		parent->next = entry->next;
	}
	delete entry;
	}
	entrysize--;
	return true;
	// } else {
	// 	std::size_t index = H()(newkey);
	// 	index = index % tablesize;
	// 	if(array[index]->next == nullptr){
	// 		array[index] == NULL;
	// 	}
	// 	else if (array[index]->key == k){
	// 		Entry *tmp = array[index]->next;
	// 		array[index] = tmp;
	// 		delete array[index->next];
	// 		array[index]->next = tmp->next;

	// 	}
	}


	template <typename KEY, typename T, typename H>
	void UnorderedMap<KEY, T, H>::rehash()
	{
		// int oldsz = tablesize;
		// tablesize = tablesize * 2;
		// tablesize = nextPrime(tablesize);
		// Entry **array2 = new Entry *[tablesize];
		// for (int i = 0; i < oldsz; i++)
		// {
		// 	Entry *n = array[i];
		// 	while (n != nullptr)
		// 	{
		// 		Entry *tmp = n;
		// 		n = n->next;
		// 		std::size_t index = H()(array[i]->key);
		// 		index = index % tablesize;
		// 		Entry *&bucket = array2[index];
		// 		tmp->next = bucket;
		// 		bucket = tmp;
		// 	}
		// }
		// delete[] array;
		// array = array2;
	}

	template <typename KEY, typename T, typename H>
	typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::find(const KEY &x) const
	{
		std::size_t index = H()(x);
		index = index % tablesize;
		Entry *tmp = array[index];
		while (tmp != nullptr)
		{
			if (tmp->key == x)
			{
				return Iterator(tmp);
			}
			tmp = tmp->next;
		}
		return end();
	}

	template <typename KEY, typename T, typename H>
	T &UnorderedMap<KEY, T, H>::operator[](const KEY &k)
	{
		static T h;
		if (find(k)==end()){
			insert(k,h);

		}
		else{
			return find(k)->data;
		}
		return find(k)->data;
	}

	template <typename KEY, typename T, typename H>
	typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::Iterator::operator++(int)
	{
		
		Iterator it = *this;
		
		if (_cur->next != nullptr)
		{
			_cur = _cur->next;
			return it;
		}
		else
		{
			KEY curkey = _cur->key;
			std::size_t index = H()(curkey);
			index = index % _tablesize;
			if(index == _tablesize){
				_cur = nullptr;
				return it;
			} else {
			//	int counter = index;
				for (int i = index+1; i < _tablesize; i++){
					if(_arr[i]!=nullptr){
						_cur = _arr[i];
						return it;
						//counter = i;
					}

				}
				_cur = nullptr;
				
				
			}
		}
		return it;
	}

	template <typename KEY, typename T, typename H>
	typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::begin() const
	{
	

		for (int i = 0; i < tablesize; i++)
		{
			if (array[i] != 0)
			{
				return Iterator(array[i], array, tablesize);
			}
		}
		return Iterator(nullptr, array, tablesize);
	}

	template <typename KEY, typename T, typename H>
	typename UnorderedMap<KEY, T, H>::Iterator UnorderedMap<KEY, T, H>::end() const
	{
		// stub code; need to implement !!!
		return Iterator(NULL);
	}

	template <typename KEY, typename T, typename H>
	typename UnorderedMap<KEY, T, H>::Entry *UnorderedMap<KEY, T, H>::Iterator::operator->()
	{
		return _cur;
	}

	template <typename KEY, typename T, typename H>
	typename UnorderedMap<KEY, T, H>::Entry &UnorderedMap<KEY, T, H>::Iterator::operator*()
	{
		return *_cur;
	}

	template <typename KEY, typename T, typename H>
	bool UnorderedMap<KEY, T, H>::Iterator::operator!=(Iterator it)
	{
		return _cur != it._cur;
	}

	template <typename KEY, typename T, typename H>
	bool UnorderedMap<KEY, T, H>::Iterator::operator==(Iterator it)
	{
		return _cur == it._cur;
	}

	// Internal method to test if a positive number is prime (not efficient)
	bool isPrime(int n)
	{
		if (n == 2 || n == 3)
			return true;
		if (n == 1 || n % 2 == 0)
			return false;
		for (int i = 3; i * i <= n; i += 2)
			if (n % i == 0)
				return false;
		return true;
	}

	// Internal method to return a prime number at least as large as n.
	// Assumes n > 0.
	int nextPrime(int n)
	{
		if (n % 2 == 0)
			n++;
		for (; !isPrime(n); n += 2)
			;
		return n;
	}
