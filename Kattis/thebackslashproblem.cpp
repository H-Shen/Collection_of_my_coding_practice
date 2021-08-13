// https://open.kattis.com/problems/thebackslashproblem

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 9;
int power[MAXN];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    power[0] = 1;
    for (int i = 1; i < MAXN; ++i) power[i] = power[i-1]<<1;
    for (int i = 1; i < MAXN; ++i) power[i] += power[i-1];
    string s, ans;
    int n;
    while (cin >> n) {
        cin.get();
        getline(cin, s);
        ans.clear();
        for (const auto &ch : s) {
            if ((ch >= '!' && ch <= '*') || (ch >= '[' && ch <= ']')) {
                for (int i = 0; i < power[n-1]; ++i) {
                    ans.push_back('\\');
                }
            }
            ans.push_back(ch);
        }
        cout << ans << '\n';
    }
    return 0;
}
