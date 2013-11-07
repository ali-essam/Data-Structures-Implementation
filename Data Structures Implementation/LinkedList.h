#include <assert.h>

template<class T>
class Node{
public:
	T value;
	Node<T>* next;
	Node(T _value);
};

template<class T>
Node<T>::Node(T _value){
	value = _value;
	next = 0;
}


template<class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void append(T _value);
	void insert(T _value,int index);
	T remove(int index);
	T& at(int index);
	int size();
	void clear();
private:
	Node<T>* nodeAt(int index);
	Node<T>* head,*tail;
	int length;
};



template<class T>
LinkedList<T>::LinkedList()
{
	head = tail = 0;
	length = 0;
}

template<class T>
LinkedList<T>::~LinkedList(){
	clear();
}

template<class T>
void LinkedList<T>::append(T _value)
{
	if(!head){
		head = tail = new Node<T>(_value);
	}
	else{
		Node<T> *toBeAdded = new Node<T>(_value);
		tail->next = toBeAdded;
		tail = toBeAdded;
	}
	length++;
}

template<class T>
void LinkedList<T>::insert(T _value, int index){
	if(index == 0){
		Node<T>* tmp = head;
		head = new Node<T>(_value);
		head->next = tmp;
		length++;
		return;
	}
	if(index == length-1){
		append(_value);
		return;
	}
	Node<T>* tmp = nodeAt(index-1);
	Node<T>* toBeInserted = new Node<T>(_value);
	toBeInserted->next = tmp->next;
	tmp->next = toBeInserted;
	length++;
}

template<class T>
T LinkedList<T>::remove(int index)
{
	assert(index<length  && index>=0);
	Node<T> *tmp;
	T ret;
	if(index==0){
		tmp = head;
		head = head->next;
		ret = tmp->value;
		delete tmp;
		length--;
		return ret;
	}

	int i=0;
	tmp = head;
	while(++i<index){
		tmp = tmp->next;
	}
	Node<T> *toBeDeleted = tmp->next;
	ret = toBeDeleted->value;
	tmp->next = toBeDeleted->next;
	if(toBeDeleted == tail)
		tail = tmp;
	delete toBeDeleted;
	length--;
	return ret;
}

template<class T>
Node<T>* LinkedList<T>::nodeAt(int index){
	assert(index<length  && index>=0);
	Node<T> *tmp;
	int i=0;
	tmp = head;
	while(++i<=index){
		tmp = tmp->next;
	}
	return tmp;
}

template<class T>
T& LinkedList<T>::at(int index){
	assert(index<length  && index>=0);
	Node<T> *tmp = nodeAt(index);
	return tmp->value;
}

template<class T>
int LinkedList<T>::size()
{
	return length;
}


template<class T>
void LinkedList<T>::clear()
{   //fsdfgsjh 3shfnshnn3
	while (length)
	{
		remove(0);
	}
	length = 0;
}