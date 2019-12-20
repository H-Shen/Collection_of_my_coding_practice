// https://www.nowcoder.com/practice/097ab63cffa847d89716f2ca8c23524f?tpId=90

#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs > rhs;
    }
};

multiset<int, cmp> A;

int main() {
    string s;
    int k;
    getline(cin, s);
    cin >> k;
    istringstream ss(s);
    string temp;
    while (getline(ss, temp, ' ')) {
        A.insert(stoi(temp));
    }
    int counter = 0;
    for (const auto &i : A) {
        if (counter == k - 1) {
            cout << i << endl;
            break;
        }
        ++counter;
    }
    return 0;
}