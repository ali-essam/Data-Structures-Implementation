template<class T>
class ArrayList
{
public:
	ArrayList();
	ArrayList(int n);
	~ArrayList();
	void append(T value);
	void insertAt(int index, T value);
	T deleteAt(int index);
	T& at(int index);
	void clear();
	int size();
private:
	void expand();
	int capacity;
	int length;
	T *arr;
};

template<class T>
ArrayList<T>::ArrayList()
{
	capacity = 10;
	length = 0;
	arr = new T[capacity];
}

template<class T>
ArrayList<T>::ArrayList(int n)
{
	capacity = n;
	length = 0;
	arr = new T[capacity];
}
template<class T>
ArrayList<T>::~ArrayList()
{
	delete[] arr;
}

template<class T>
void ArrayList<T>::append(T value){
	if(length==capacity) expand();
	arr[length++] = value;
}

template<class T>
void ArrayList<T>::insertAt(int index, T value){
	if(length==capacity) expand();
	for (int i = length; i > index; i--)
		arr[i]=arr[i-1];
	arr[index] = value;
	length++;
}

template<class T>
T ArrayList<T>::deleteAt(int index){
	length--;
	T tmp = arr[index];
	for (int i = index; i < length; i++)
		arr[i]=arr[i+1];
	return tmp;
}

template<class T>
T& ArrayList<T>::at(int index){
	return arr[index];
}

template<class T>
int ArrayList<T>::size(){
	return length;
}

template<class T>
void ArrayList<T>::clear(){
	length = 0;
}

template<class T>
void ArrayList<T>::expand(){
	capacity*=2;
	T* tmp = new T[capacity];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}