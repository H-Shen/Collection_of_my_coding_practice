#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#define FILE_BUFFER_LENGTH 300000
using namespace std;

class AbstractArrayList {
private:
    int* elementData;
    int capacity;
    int size;

public:
    AbstractArrayList() {
        capacity = 10;
        elementData = new int[capacity];
        size = 0;
    }

    ~AbstractArrayList() {
        delete[] elementData;
    }

    int* copyArray(int original, const int newLength) {
        int* copy = new int[newLength];
        for (int i = 0; i < original; i++) {
            copy[i] = elementData[i];
        }
        delete[] elementData;
        return copy;
    }

    void ensureCapacityInternal(int minCapacity) {
        if (minCapacity - capacity > 0) {
            capacity *= 2;
            elementData = copyArray(size, capacity);
        }
    }

    void append(int element) {
        ensureCapacityInternal(size + 1);
        this_thread::sleep_for(chrono::microseconds(1000));
        elementData[size] = element;
        this_thread::sleep_for(chrono::microseconds(1000));
        size++;
    }

    int get(int index) {
        if (index >= size)
            return -1;
        return elementData[index];
    }

    int getSize() {
        return size;
    }
};


