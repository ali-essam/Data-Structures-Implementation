#include <assert.h>
template<class T>
class StackNode{
public:
	T data;
	StackNode<T>* next;
	StackNode():data(0),next(0){}
	StackNode(T _data):data(_data),next(0){}
};

template<class T>
class Stack{
	int length;
	StackNode<T>* topNode;
public:
	Stack();
	~Stack();
	void push(T val);
	T& top();
	T pop();
	int size();
	bool empty();
	void clear();
};


template<class T>
Stack<T>::Stack(){
	topNode = 0;
	length = 0;
}

template<class T>
Stack<T>::~Stack(){
	empty();
}

template<class T>
int Stack<T>::size(){
	return length;
}

template<class T>
bool Stack<T>::empty(){
	return !length;
}

template<class T>
void Stack<T>::push(T val){
	StackNode<T>* tmp = new StackNode<T>(val);
	tmp->next = topNode;
	topNode = tmp;
	++length;
}

template<class T>
T& Stack<T>::top(){
	assert(!empty());
	return topNode->data;
}

template<class T>
T Stack<T>::pop(){
	assert(!empty());
	StackNode<T>* tmp = topNode;
	T data = topNode->data;
	topNode = topNode->next;
	delete tmp;
	--length;
	return data;
}


template<class T>
void Stack<T>::clear(){
	while (!empty())
		pop();
}
