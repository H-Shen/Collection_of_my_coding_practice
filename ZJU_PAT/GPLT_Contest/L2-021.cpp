#include <bits/stdc++.h>

using namespace std;

struct User {
    string id;
    int uniqueSize;
    int totalSize;
};

bool cmp(const User &a, const User &b) {
    if (a.uniqueSize == b.uniqueSize) {
        return (a.totalSize < b.totalSize);
    }
    return (a.uniqueSize > b.uniqueSize);
}

int main() {

    int n, m, i, j;
    string id;
    cin >> n;
    vector<User> A(n);

    for (j = 0; j < n; ++j) {
        cin >> id >> m;
        vector<int> tmp(m);
        for (i = 0; i < m; ++i) {
            cin >> tmp[i];
        }
        unordered_set<int> tmpSet(tmp.begin(), tmp.end());
        A[j].uniqueSize = tmpSet.size();
        A[j].totalSize = m;
        A[j].id = id;
    }

    sort(A.begin(), A.end(), cmp);
    for (i = 0; i < 2; ++i) {
        try {
            cout << A.at(i).id << ' ';
        } catch (...) {
            cout << "- ";
        }
    }
    try {
        cout << A.at(2).id << endl;
    } catch (...) {
        cout << "-" << endl;
    }
    return 0;
}