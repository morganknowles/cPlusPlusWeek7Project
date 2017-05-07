#include <iostream>
#include <string>
#include <exception>
using namespace std;
/*
Morgan Knowles
12/11/2016
Microsoft Visual Studio

*/

template <typename T>
class ArrayList {
private:
	T * data;
	int howmany;
	int arraySize;//size of allocated array (ie capacity of object)

public:
	//constructors
	ArrayList();//creates ArrayList with size of 10
	ArrayList(int cap);//creates ArrayList with capacity of cap
	ArrayList(const ArrayList<T>& obj); //copy constructor

	//destructors
	~ArrayList();

	//mutators
	void add(T value);//adds new value to the end of this list
	void ensureCapacity(int cap); //assures that there is room for 'cap' items in this ArrayList, resizing if necessary
	void set(int index, T value); //replaces element at index with new value
	void add(int index, T value);//adds new element at index, shifting existing data to right
	void clear();//clears this ArrayList of all data, and returns to initial state
	T remove(int index);//removes item at index, shifting remaining data to the left. returns value that is removed.

	//accessors
	int size();//returns the number of values in this list
	T get(int index);//returns value at index
	int indexOf(T value); //returns the index of the first occurence of value, -1 returned if value is not found
	bool contains(T value);//returns true if value is in this ArrayList
	bool isEmpty(); //returns true if this ArrayList is empty

	//operators
	ArrayList<T>& operator =(const ArrayList<T>& obj);//assignment overload
	ArrayList<T> operator +(const ArrayList<T>& list);//returns a new ArrayList containing the data from Arraylist 'list' appended to this ArrayList
};

//constructors
template <typename T>
ArrayList<T>::ArrayList() {//creates ArrayList with size of 10
	data = new T[10];
	howmany = 0;
	arraySize = 10;
}
template <typename T>
ArrayList<T>::ArrayList(int cap) {//creates ArrayList with capacity of cap
	data = new T[cap];
	howmany = 0;
	arraySize = cap;
}
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& obj) { //copy constructor
	data = new T[obj.arraySize];

	for (int i = 0; i< obj.howmany; i++) {
		data[i] = obj.data[i];
	}
	howmany = obj.howmany;
	arraySize = obj.arraySize;
}

//destructors
template <typename T>
ArrayList<T>::~ArrayList() {
	delete data;
	return;
}

//mutators
template <typename T>
void ArrayList<T>::add(T value) {//adds new value to the end of this list
	ensureCapacity(howmany + 1);
	data[howmany] = value;
	howmany++;
}
template <typename T>
void ArrayList<T>::ensureCapacity(int cap) { //assures that there is room for 'cap' items in this ArrayList, resizing if necessary
	if (arraySize < cap) {
		arraySize =arraySize + (cap - arraySize);
		T * temp = new T[arraySize];
		for (int i = 0; i < howmany; i++) {
			temp[i] = data[i];
		}
		data = temp;
	}
}
template <typename T>
void ArrayList<T>::set(int index, T value) { //replaces element at index with new value
	if (index < 0 || index >= size()) {
		throw invalid_argument("Index is out of range");
	}
	else {
		data[index] = value;
	}
}

template <typename T>
void ArrayList<T>::add(int index, T value) {//adds new element at index, shifting existing data to right
	if (index < 0 || index >= arraySize) {
		throw invalid_argument("Index is out of range");
	}
	else {	
		ensureCapacity(howmany + 1);
		for (int i = howmany - 1; i > index; i--) {
			data[i + 1] = data[i];
		}
		howmany++;
		data[index] = value;
	}
}


template <typename T>
void ArrayList<T>::clear() {//clears this ArrayList of all data, and returns to initial state
	delete data;
	howmany = 0;
	arraySize = 0;
	
	
}
template <typename T>
T ArrayList<T>::remove(int index) {//removes item at index, shifting remaining data to the left. returns value that is removed.
	if (index < 0 || index >= arraySize) {
		throw invalid_argument("Index is out of range");
	}
	else {
		T  d = data[index];
		for (int i = index; i < howmany; i++) {
			data[i] = data[i + 1];
		}
		howmany--;
		return d;
	}
}

//accessors
template <typename T>
int ArrayList<T>::size() {//returns the number of values in this list
		return howmany;
}
template <typename T>
T ArrayList<T>::get(int index) {//returns value at index
	if (index < 0 || index >= size()) {
		throw invalid_argument("Index is out of range");
	}
	else {
		return data[index];
	}
}

template <typename T>
int ArrayList<T>::indexOf(T value) { //returns the index of the first occurence of value, -1 returned if value is not found
	for (int i = 0; i < howmany; i++) {
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}
template <typename T>
bool ArrayList<T>::contains(T value) {//returns true if value is in this ArrayList
	for (int i = 0; i < howmany; i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}
template <typename T>
bool ArrayList<T>::isEmpty() { //returns true if this ArrayList is empty
	if (arraySize == 0 || howmany == 0) {
		return true;
	}
	else {
		return false;
	}
}
//operators
template <typename T>
ArrayList<T>&  ArrayList<T>::operator =(const ArrayList<T>& obj) {//assignment overload
	if (this != &obj) {
		delete[] data;
		data = new T[obj.arraySize];
		howmany = obj.howmany;
		arraySize = obj.arraySize;
		for (int i = 0; i < obj.howmany; i++) {
			this->data[i] = obj.data[i];
		}
	}
	return *this;
}

template <typename T>
ArrayList<T> ArrayList<T>::operator +(const ArrayList<T>& list) {//returns a new ArrayList containing the data from Arraylist 'list' appended to this ArrayList
	 ArrayList<T>temp(this->arraySize + list.arraySize);
	 for (int i =0; i < this->howmany; i++) {
		 temp.add(this->get(i));
	}
	 for (int i = 0; i <list.howmany; i++) {
		 temp.data[this->howmany + i] = list.data[i];
		 temp.howmany++;
	 }
	return temp;
}


