// https://www.nowcoder.com/practice/673454422d1b4a168aed31e449d87c00

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> A;
    char ch;
    int n;
    while (true) {
        cin >> ch;
        if (ch == ']') {
            break;
        }
        cin >> n;
        A.push_back(n);
    }

    int firstMax = INT_MIN;
    int firstMaxIdx = -1;
    for (size_t i = 0; i != A.size(); ++i) {
        if (A[i] >= firstMax) {
            firstMax = A[i];
            firstMaxIdx = i;
        }
    }

    int secondMax = INT_MIN;
    int secondMaxIdx = -1;
    for (size_t i = 0; i != A.size(); ++i) {
        if (A[i] <= firstMax && A[i] >= secondMax && firstMaxIdx != static_cast<int>(i)) {
            secondMax = A[i];
            secondMaxIdx = i;
        }
    }

    int thirdMax = INT_MIN;
    for (size_t i = 0; i != A.size(); ++i) {
        if (A[i] <= secondMax && A[i] >= thirdMax && secondMaxIdx != static_cast<int>(i)) {
            thirdMax = A[i];
        }
    }

    cout << thirdMax << endl;
    return 0;
}