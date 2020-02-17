#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A) {
        cin >> i;
    }

    int counter = 0;
    while (n > 0) {
        for (int i = 0; i < n - 1; ++i) {
            if (A.at(i) > A.at(i + 1)) {
                swap(A.at(i), A.at(i + 1));
                ++counter;
            }
        }
        --n;
    }
    cout << "Array is sorted in " << counter << " swaps." << endl;
    cout << "First Element: " << A.front() << endl;
    cout << "Last Element: " << A.back() << endl;

    return 0;
}
