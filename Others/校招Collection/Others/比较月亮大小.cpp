// https://ac.nowcoder.com/acm/problem/15431

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 300;
vector<int> A(maxn);

void pre() {
    bool increase = true;
    int currentVal = 0;
    for (int i = 0; i < maxn; ++i) {
        A[i] = currentVal;
        if (currentVal == 0) {
            increase = true;
            ++currentVal;
            continue;
        }
        if (currentVal == 15) {
            increase = false;
            --currentVal;
            continue;
        }
        if (increase) {
            ++currentVal;
        } else {
            --currentVal;
        }
    }
}

int main() {
    pre();
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> logList(n);
    for (auto &p : logList) {
        cin >> p;
    }

    auto it = search(A.begin(), A.end(), logList.begin(), logList.end());
    if ((n == 1 && logList.back() >= 1 && logList.back() < 15) || it == A.end()) {
        cout << "-1";
    } else {
        int diff = A[distance(A.begin(), it) + logList.size()] - logList.back();
        if (diff < 0) {
            cout << "DOWN";
        } else {
            cout << "UP";
        }
    }
    cout << endl;
    return 0;
}