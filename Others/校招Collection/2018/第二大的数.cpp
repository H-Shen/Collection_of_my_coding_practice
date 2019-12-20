// https://www.nowcoder.com/practice/ce710d3a27ca475b97bbae0cb227f1b5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n <= 0) {
        return 0;
    }

    vector<int> A(n);
    for (auto &&i : A) {
        cin >> i;
    }
    int maxVal = *max_element(A.begin(), A.end());
    int secondLargest = -1;
    bool hasSecondLargest = false;
    for (const auto &i : A) {
        if (i != maxVal) {
            secondLargest = i;
            hasSecondLargest = true;
            break;
        }
    }

    for (const auto &i : A) {
        if (i != maxVal) {
            secondLargest = max(secondLargest, i);
        }
    }

    if (hasSecondLargest) {
        cout << secondLargest;
    } else {
        cout << maxVal;
    }
    cout << endl;
    return 0;
}