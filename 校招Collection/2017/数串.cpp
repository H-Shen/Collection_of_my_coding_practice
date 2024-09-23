// https://www.nowcoder.com/practice/a6a656249f404eb498d16b2f8eaa2c60

#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b) {
    return (a + b) > (b + a);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<string> A(n);
        for (auto &i : A) cin >> i;
        sort(A.begin(), A.end(), cmp);
        for (auto &i : A) cout << i;
        cout << endl;
    }
    return 0;
}