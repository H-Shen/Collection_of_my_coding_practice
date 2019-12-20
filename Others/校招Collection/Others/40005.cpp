#include <bits/stdc++.h>

/**
 * Design a class Array2 to implement a two-dimension array.
 */
using namespace std;

class Array2 {
public:

    int **arr = nullptr;
    int m = 0, n = 0;
    int currentCol = 0;

    Array2() {}

    Array2(int a, int b) {
        m = a;
        n = b;
        arr = new int *[m];
        for (int i = 0; i < m; ++i) {
            arr[i] = new int[n];
        }
    }

    ~Array2() {
        for (int i = 0; i < m; ++i) {
            delete[]arr[i];
        }
        delete[]arr;
        arr = nullptr;
    }

    int *operator[](int i) {
        currentCol = i;
        return arr[currentCol];
    }

    int &operator[](int j) const {
        return arr[currentCol][j];
    }

    int &operator()(int i, int j) {
        return arr[i][j];
    }

    void operator=(const Array2 &other) {

        m = other.m;
        n = other.n;
        arr = new int *[m];
        for (int i = 0; i < m; ++i) {
            arr[i] = new int[n];
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;

    Array2 b;
    b = a;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            assert(b[i][j] == a[i][j]);
        }
    }
    return 0;
}