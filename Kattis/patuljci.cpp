// https://open.kattis.com/problems/patuljci

#include <bits/extc++.h>

using namespace std;
const int maxn = 9;

int main() {
    vector<int> A(maxn);
    unordered_set<int> filter;
    int sum = 0;
    for (auto &&i : A) {
        cin >> i;
        sum += i;
    }
    bool hasAns = false;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        if (hasAns) {
            break;
        }
        for (size_t j = i + 1; j < A.size(); ++j) {
            if (sum - A[i] - A[j] == 100) {
                filter.insert(A[i]);
                filter.insert(A[j]);
                hasAns = true;
                break;
            }
        }
    }
    for (const auto &i : A) {
        if (filter.find(i) == filter.end()) {
            cout << i << endl;
        }
    }
    return 0;
}
