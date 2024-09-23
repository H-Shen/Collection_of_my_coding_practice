#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;

void handle(string &s) {
    s = string(MAXN - s.size(), '0') + s;
}

string deleteTailZero(const string &s) {
    int len = static_cast<int>(s.size());
    if (len == 1 && s == "0") return s;
    string res;
    int i;

    for (i = 0; i < len; ++i) {
        if (s[i] != '0') {
            break;
        }
    }
    res = s.substr(i);
    if (res.empty())
        res = "0";
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    string a, b, c, d;
    cin >> a >> b >> c;
    handle(a);
    handle(b);
    handle(c);
    handle(d);

    int i, radix;
    int carry = 0;
    int res = 0;

    for (i = MAXN - 1; i >= 0; --i) {
        radix = a[i] - '0';
        if (radix == 0) radix = 10;
        res = (b[i] - '0' + c[i] - '0' + carry) % radix;
        carry = (b[i] - '0' + c[i] - '0' + carry) / radix;
        d[i] = static_cast<char>(res + '0');
    }
    cout << deleteTailZero(d) << endl;

    return 0;
}