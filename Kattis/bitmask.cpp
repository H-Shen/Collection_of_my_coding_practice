// https://open.kattis.com/problems/bitmask

#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 15;
int cost[MAXN];
int n;
string s;
int minCost = numeric_limits<int>::max();

void dfs(int currentIndex, unordered_set<string> unset, int currentCost) {
    if (currentCost >= minCost) {
        return;
    }
    if (currentIndex == n) {
        minCost = min(minCost, currentCost);
        return;
    }
    string str;
    for (int i = currentIndex; i < n; ++i) {
        str.push_back(s[i]);
        if (unset.find(str) == unset.end()) {
            unset.insert(str);
            currentCost += cost[str.length()];
            dfs(i+1, unset, currentCost);
            // restore
            unset.erase(str);
            currentCost -= cost[str.length()];
        }
        else {
            dfs(i+1, unset, currentCost);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    for (auto&i : s) {
        if (i == '0') i = '1';
        else i = '0';
    }
    n = (int)s.size();
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    string str;
    for (int i = 0; i < n; ++i) {
        str.push_back(s[i]);
        dfs(i+1, unordered_set<string>{str}, cost[str.length()]);
    }
    cout << minCost << '\n';
    return 0;
}
