// https://www.nowcoder.com/practice/7f26bfeccfa44a17b6b269621304dd4a

#include <bits/stdc++.h>

using namespace std;

size_t Search(string &s, int &len) {
    int i;
    int lastVal = s[0], res = 0;
    for (i = 1; i < len; i++) {
        if (lastVal < s[i]) {
            res = i - 1;
            break;
        } else {
            lastVal = s[i];
            res = i;
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s) {

        int m, i;
        cin >> m;
        int len = s.size();

        for (i = 0; i < m; i++) {
            size_t pos = Search(s, len);
            s.erase(pos, 1);
            len--;
        }

        cout << s << endl;
    }
    return 0;
}