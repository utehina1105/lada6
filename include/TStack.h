#pragma once

template <class T>
class TStack {
private:
  int  size;
  int count;
  T* data;
  
public:
  TStack(int _size = 1);
  TStack(const TStack<T> &p);
  ~TStack();
  void push(T &temp);
  T pull();
  int getCount();
  int getSize();
  bool isFull();
  bool isEmpty();
  T top();
};

template <class T>
T TStack<T>::top() {
  T elem;
  if (count < 0) throw "error"
  else {
    elem = data[count];
    return elem;
  }
}


template <class T>
TStack<T>::TStack(int _size) {
  if (_size < 0) throw "Error with size";
  size = _size;
  count = 0;
  data = new T[size];
  for (int i = 0; i < size; i++)
    data[i] = 0;
}

template <class T>
TStack<T>::TStack(const TStack<T>& p) {
  if (p.size < 0) throw "Error with size";
  size = p.size;
  count = p.count;
  data = new T[size];
  for (int i = 0; i < size; i++)
    data[i] = p.data[i];
}

template <class T>
TStack<T>::~TStack() {
  delete[] data;
  size = 0;
  count = 0;
}

template <class T>
void TStack<T>::push(T& temp) {
  if (count > size) throw "Error with size";
  else {
	data[count] = a;
	count++;
  }
}

template <class T>
T TStack<T>::pull() {
  if (count > size) throw "Error with size";
  T temp;
  temp = data[count];
  count--;
  return temp;
}

template <class T>
int TStack<T>::getCount() {
  return count;
}

template <class T>
int TStack<T>::getSize() {
  return size;
}

template <class T>
bool TStack<T>::isFull() {
  if (count > size) throw "Error with size";
  int res = 0;
  if (count == size)
    res = 1;
  return res;
}

template <class T>
bool TStack<T>::isEmpty() {
  if (count > size) throw "Error with size";
  int res = 0;
  if (count == 0)
    res = 1;
  return res;
}