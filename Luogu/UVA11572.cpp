#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(const vector<int> &A) {
    int ret = 0;
    int tail = 0;
    int head = 0;
    unordered_set<int> temp_set;
    int n = static_cast<int>(A.size());
    while (head < n) {
        if (temp_set.find(A.at(head)) == temp_set.end()) {
            temp_set.insert(A.at(head));
            ret = max(ret, head - tail + 1);
            ++head;
        } else {
            while (temp_set.find(A.at(head)) != temp_set.end() && tail != head) {
                temp_set.erase(A.at(tail));
                ++tail;
            }
            if (tail == head) {
                temp_set.insert(A.at(head));
                ret = max(ret, head - tail + 1);
                ++head;
            }
        }
    }
    return ret;
}

int main() {

    int t;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> A(n);
        for (auto &i : A) {
            scanf("%d", &i);
        }
        printf("%d\n", solve(A));
    }

    return 0;
}
