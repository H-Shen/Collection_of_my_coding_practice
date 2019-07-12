// https://www.nowcoder.com/practice/11c9f023a9f84418a15b48792a5f7c70

#include <iostream>
#include <vector>

using namespace std;

const int MIN = 100;
const int MAX = 999;

inline
bool isNum(const int &n) {
    int sum = 0;
    int temp;
    int n_copy = n;
    while (n_copy > 0) {
        temp = n_copy % 10;
        sum += temp * temp * temp;
        n_copy /= 10;
    }
    return (sum == n);
}

int main() {

    // pre
    vector<int> A;
    for (int i = MIN; i <= MAX; ++i) {
        if (isNum(i)) {
            A.emplace_back(i);
        }
    }

    int m, n;
    bool firstItem;
    while (cin >> m >> n) {
        vector<int> result;
        for (const auto &i : A) {
            if (i >= m && i <= n) {
                result.emplace_back(i);
            }
        }
        if (result.empty()) {
            cout << "no";
        } else {
            firstItem = true;
            for (const auto &j : result) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << " ";
                }
                cout << j;
            }
        }
        cout << endl;
    }
    return 0;
}