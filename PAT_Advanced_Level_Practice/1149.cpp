#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_set<string> > A;
unordered_set<string> itemSet;

int main() {
    int n, m, items;
    cin >> n >> m;
    string a, b, itemNum;
    bool hasAns = true;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        A[a].insert(b);
        A[b].insert(a);
    }
    for (int i = 0; i < m; ++i) {
        cin >> items;
        itemSet.clear();
        for (int j = 0; j < items; ++j) {
            cin >> itemNum;
            itemSet.insert(itemNum);
        }
        hasAns = true;
        for (auto it = itemSet.cbegin(); it != itemSet.cend(); ++it) {
            if (A.find(*it) != A.end()) {
                for (auto it2 = A[*it].cbegin(); it2 != A[*it].cend(); ++it2) {
                    if (itemSet.find(*it2) != itemSet.end()) {
                        hasAns = false;
                        break;
                    }

                }
            }
            if (!hasAns) {
                break;
            }
        }

        if (hasAns) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}