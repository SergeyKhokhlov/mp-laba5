#pragma once
using namespace std;
template <class T>
class TQueue {
private:
    int size;
    int start;
    int end;
    T* data;

public:
    TQueue(int _size = 1);
    TQueue(const TQueue& p);
    ~TQueue();
    void push(T& temp); 
    T pull();
    int getCount();
    int getStart();
    int getEnd();
    int getSize();
    bool isFull();
    bool isEmpty();
    int busy_checker();
};

template <class T>
TQueue<T>::TQueue(int _size) {
    if (_size < 0) throw "Error with size";
    size = _size;
    start = 0;
    end = 0;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue& p) {
    if (p.size < 0) throw "Error with size";
    size = p.size;
    start = p.start;
    end = p.start;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = p.data[i];
}

template <class T>
TQueue<T>::~TQueue() {
    delete[] data;
    size = 0;
    start = 0;
    end = 0;
}

template <class T>
void TQueue<T>::push(T& temp) {
    if (isFull()) throw "Error with size";
    if (end >= size)
        if (start > 0)
            end = 0;
    data[end] = temp;
    end++;
}

template<typename int>
inline int TQueue<int>::busy_checker(void) const {
    if (IsEmpty())
        throw "Err";
    return data[start];
}

template <class T>
T TQueue<T>::pull() {
    if (start < 0) throw "Error with size";
    if (isEmpty()) throw "Error with size";
    T temp;
    if (start > size) {
        if (end > 0) {
            temp = data[0];
            start = 0;
        }
        else
            throw "Error with size";
    }
    temp = data[start];
    start++;
    return temp;
}

template <class T>
int TQueue<T>::getCount() {
    int res = end - start;
    if (end < start)
        res = size - start + end;
    return res;
}

template <class T>
int TQueue<T>::getStart() {
    return start;
}

template <class T>
int TQueue<T>::getEnd() {
    return end;
}

template <class T>
int TQueue<T>::getSize() {
    return size;
}

template <class T>
bool TQueue<T>::isFull() {
    int res = false;
    int count = getCount();
    if (count == size)
        res = true;
    return res;
}

template <class T>
bool TQueue<T>::isEmpty() {
    if (start < 0) throw "Error with size";
    int res = false;
    if (start == end)
        res = true;
    return res;
}