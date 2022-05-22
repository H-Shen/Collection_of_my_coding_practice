#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map<string, int> dict;
int n, m;
vector<string> words;
int counter;

inline
bool check(int length) {
    unordered_map<string, int> vis;
    int maxVal = 0;
    // 滑动窗口
    for (int i = 0; i < length; ++i) {
        if (dict.count(words[i]) > 0) {
            ++vis[words[i]];
            maxVal = max(maxVal, (int)vis.size());
        }
    }
    for (int i = length, j = 0; i < m; ++i, ++j) {
        if (vis.count(words[j]) > 0) {
            --vis[words[j]];
            if (vis[words[j]] == 0) {
                vis.erase(words[j]);
            }
        }
        if (dict.count(words[i]) > 0) {
            ++vis[words[i]];
            maxVal = max(maxVal, (int)vis.size());
        }
    }
    return maxVal == counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        dict[s] = 0;
    }
    cin >> m;
    words.resize(m);
    for (auto&i : words) {
        cin >> i;
        auto iter = dict.find(i);
        if (iter != dict.end()) {
            if (iter->second == 0) {
                ++counter;
                iter->second = 1;
            }
        }
    }
    // corner case
    if (counter == 0) {
        cout << counter << '\n';
        cout << 0 << '\n';
        return 0;
    }
    // 二分连续段的长度
    int ans = numeric_limits<int>::max();
    int l = 1;
    int r = m;
    int mid;
    while (l <= r) {
        mid = l + ((r-l)>>1);
        if (check(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << counter << '\n';
    cout << ans << '\n';
    return 0;
}