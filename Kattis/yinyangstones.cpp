// https://open.kattis.com/problems/yinyangstones

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    unordered_map<char, int> cnt;
    string s;
    cin >> s;
    for (const auto &ch : s) {
        ++cnt[ch];
    }
    if (cnt['W'] == cnt['B']) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << endl;
}
