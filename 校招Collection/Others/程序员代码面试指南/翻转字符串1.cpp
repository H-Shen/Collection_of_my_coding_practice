// https://www.nowcoder.com/practice/972117dd8f334076a5df6a68b0a8f3dd

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    vector<string> A;
    while (cin >> s) {
        reverse(s.begin(), s.end());
        A.emplace_back(s);
    }
    bool firstItem{true};
    for (const string &i: A) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << endl;
    return 0;
}