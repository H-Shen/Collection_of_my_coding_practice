// https://www.nowcoder.com/practice/df0d850e41894d06a165bf445ec8a8b4

#include <iostream>

using namespace std;
const int MIN = 2, MAX = 60;

int sumOfDivisors(const int &n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}


int main() {

    cout << "E: ";
    for (int i = MIN; i <= MAX; ++i) {
        if (sumOfDivisors(i) == i) {
            cout << i << ' ';
        }
    }
    cout << "G: 2 ";
    bool firstItem = true;
    for (int i = MIN; i <= MAX; ++i) {
        if (sumOfDivisors(i) > i) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
    }

    return 0;
}