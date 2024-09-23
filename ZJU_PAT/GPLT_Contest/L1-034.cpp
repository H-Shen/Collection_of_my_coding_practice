#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> A;

int main() {
    int n, k, id;
    cin >> n;
    while (n--) {
        cin >> k;
        while (k--) {
            cin >> id;
            if (A.find(id) == A.end()) {
                A[id] = 1;
            } else {
                A[id]++;
            }
        }
    }
    auto it = A.begin();
    int maxN = -1, maxId = -1;
    for (; it != A.end(); ++it) {
        maxN = max(maxN, it->second);
    }
    for (it = A.begin(); it != A.end(); ++it) {
        if (it->second == maxN) {
            maxId = max(maxId, it->first);
        }
    }
    cout << maxId << ' ' << A[maxId] << endl;
    return 0;
}