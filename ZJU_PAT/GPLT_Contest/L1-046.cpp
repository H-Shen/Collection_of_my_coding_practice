#include <bits/stdc++.h>

using namespace std;

string highPrecDivLowPrec(string &a, int &b, int nn) {

    string r, ans;
    int d = 0;

    if (a == "0")
        return a;

    int len_a = a.size();
    for (int i = 0; i < len_a; i++) {
        r += (d * 10 + a[i] - '0') / b + '0';
        d = (d * 10 + (a[i] - '0')) % b;
    }

    int p = 0;
    int len_r = r.size();

    for (int i = 0; i < len_r; i++) {
        if (r[i] != '0') {
            p = i;
            break;
        }
    }

    if (nn == 1)
        return r.substr(p);
    return to_string(d);
}

int main() {

    int n;
    cin >> n;
    string s = "1";
    int cnt = 1;
    while (highPrecDivLowPrec(s, n, 2) != "0") {
        s = "1" + s;
        ++cnt;
    }
    cout << highPrecDivLowPrec(s, n, 1) << ' ' << cnt << endl;

    return 0;
}