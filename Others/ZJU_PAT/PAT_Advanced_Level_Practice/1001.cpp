#include <bits/stdc++.h>

using namespace std;

const int limits = 3;
const char delimiter = ',';

int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a + b;
    int cnt = 0;
    int i = 0;

    string s = to_string(c);
    deque<char> res;
    int len = s.size();


    for (i = len - 1; i >= 0; --i) {
        if (s[i] == '-') {
            res.push_front('-');
            break;
        }
        if (cnt == limits) {
            res.push_front(delimiter);
            cnt = 1;
        } else {
            ++cnt;
        }
        res.push_front(s[i]);
    }

    for (const auto &p : res) printf("%c", p);
    putchar('\n');

    return 0;
}
