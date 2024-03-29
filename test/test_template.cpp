#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array {
    friend int main();
    private:
        T* arr;
        int size;

        static int capacity;
};

template <class T> int Array<T>::capacity = 10;

int main() {
    Array<float>::capacity = 20;
    cout << Array<int>::capacity << endl;
}