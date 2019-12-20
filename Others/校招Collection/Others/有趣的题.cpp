// https://ac.nowcoder.com/acm/problem/17195

#include <bits/stdc++.h>

using namespace std;
const int N = 6;

int main() {
    unordered_map<int, int> cnt;
    int len;
    for (int i = 0; i < N; ++i) {
        cin >> len;
        ++cnt[len];
    }

    string s;
    for (auto it = cnt.cbegin(); it != cnt.cend(); ++it) {
        s = s + to_string(it->second);
    }
    sort(s.begin(), s.end());
    if (s == "114" || s == "15") {
        cout << "Bear";
    } else if (s == "6" || s == "24") {
        cout << "Elephant";
    } else {
        cout << "Hernia";
    }
    cout << endl;

    return 0;
}