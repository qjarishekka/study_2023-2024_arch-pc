#include<iostream>
#include<cmath>
#include<cstring>
#define DEBUG

using namespace std;

template<class T>
class MyVector {
public:
    MyVector() : length(0), capacity(1), data(new T[1]) {}

    MyVector(const MyVector& vec) : length(vec.length), capacity(vec.capacity), data(new T[vec.capacity]) { for (int i = 0; i < length; i++) data[i] = vec.At(i); }

    MyVector(T* newData, int newLength) : length(newLength), capacity(newLength), data(new T[newLength]) { for (int i = 0; i < length; i++) data[i] = newData[i]; }

    ~MyVector() { delete[] data; }

    MyVector& operator=(const MyVector& vec) { UpCapacity(vec.Capacity()); for (int i = 0; i < vec.Length(); i++) data[i] = vec.At(i); length = vec.Length(); return *this; }

    void PushBack(T newElement) { UpCapacity(length + 1); data[length++] = newElement; }

    int& operator[] (int index) { return data[index]; }

    bool IsEmpty() const { return length == 0; }

    int Length() const { return length; }

    int Capacity() const { return capacity; }

    const int& At(int index) const { return data[index]; }

private:

    void UpCapacity(int newLength) {
        if (newLength > capacity) {
            T* newdata = new T[newLength];
            for (int i = 0; i < length; i++) newdata[i] = data[i];
            delete[] data;
            data = newdata;
            capacity = newLength;
        }
    }
    int length;
    int capacity;
    T* data;
};


template<typename T>
void InputMyVector(MyVector<T>& vec, int l) {
    for (int i = 0; i < l; i++)
        vec.PushBack(rand() % 200 - 100);
}


template<typename T>
void OutputMyVector(const MyVector<T>& vec) {
    for (int i = 0; i < vec.Length(); i++)
        cout << vec.At(i) << " ";
    cout << endl;
}

template<class T>
void Swap(T& m1, T& m2) {
    T m3 = m1;
    m1 = m2;
    m2 = m3;
}

int main(int argc, char* argv[]) {        

    setlocale(0, "rus");
    srand(1);

    MyVector<int> a, b;

    InputMyVector(a, 10);
    InputMyVector(b, 4);
    OutputMyVector(a);
    OutputMyVector(b);
    Swap(a, b);
    OutputMyVector(a);
    OutputMyVector(b);

    int c[] = { 1,2,3,4,5,6,7,8,9,10 };
    MyVector<int> d(c, 10);
    OutputMyVector(d);

    return 0;
}
