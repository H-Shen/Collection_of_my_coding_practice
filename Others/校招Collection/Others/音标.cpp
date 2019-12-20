// https://ac.nowcoder.com/acm/problem/15668

#include <bits/stdc++.h>

using namespace std;

char a[] = "aaaaeeeeiiiiiioooooouuuuyy";

int main() {
    ios_base::sync_with_stdio(false);
    string s, res;
    int pos = 0;
    while (cin >> s) {
        res = s;
        pos = 0;
        for (const auto &i : s) {
            res[pos++] = a[static_cast<int>(i - 'a')];
        }
        cout << res << endl;
    }

    return 0;
}