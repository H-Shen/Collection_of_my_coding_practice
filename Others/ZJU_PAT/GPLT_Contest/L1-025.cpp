#include <bits/stdc++.h>

using namespace std;

const int maxn = 2;

bool judge(const string &s) {

    int tmp = 0;

    try {
        tmp = stoi(s);
    } catch (...) {
        return false;
    }

    if (to_string(tmp) != s) {
        return false;
    }

    return (tmp >= 1 && tmp <= 1000);
}

int main() {

    string s, s_a, s_b;
    int a = 0;
    int b = 0;
    int cnt = 0;
    bool haveNoAns = false;

    while (true) {

        if (cnt == maxn) {
            break;
        }
        if (cnt == 0) {
            cin >> s;
            getchar();
            if (judge(s)) {
                s_a = s;
                a = stoi(s);
            } else {
                s_a = "?";
                haveNoAns = true;
            }
            ++cnt;
        } else if (cnt == 1) {
            getline(cin, s);
            if (judge(s)) {
                s_b = s;
                b = stoi(s);
            } else {
                s_b = "?";
                haveNoAns = true;
            }
            ++cnt;
        }
    }


    cout << s_a << " + " << s_b << " = ";
    if (haveNoAns) {
        cout << "?" << endl;
    } else {
        cout << a + b << endl;
    }

    return 0;
}