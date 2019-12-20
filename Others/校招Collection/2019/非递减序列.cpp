// https://www.nowcoder.com/practice/752409657fee4fddbac587fb30fd59b6

#include <iostream>
#include <vector>

using namespace std;

bool checkIncrease(const vector<int> &A, int i) {
    bool result = false;
    try {
        if (A.at(i - 1) < A.at(i) && A.at(i) > A.at(i + 1)) {
            result = true;
        }
    } catch (...) {}
    return result;
}

int main() {

    vector<int> A;
    int n;
    while (cin >> n) {
        A.emplace_back(n);
    }
    int counter = 0;
    int len = static_cast<int>(A.size());
    for (int i = 0; i < len; ++i) {
        if (checkIncrease(A, i)) {
            A.at(i) = A.at(i - 1);
            ++counter;
        }
    }
    if (counter <= 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << endl;
    return 0;
}