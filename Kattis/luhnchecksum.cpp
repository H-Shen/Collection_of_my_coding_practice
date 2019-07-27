// https://open.kattis.com/problems/luhnchecksum
//
#include<bits/stdc++.h>

using namespace std;

inline
int handle(char ch) {
    int n = ch - '0';
    n *= 2;
    if (n < 10) {
        return n;
    }
    string s = to_string(n);
    n = (s[0] - '0') + (s[1] - '0');
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n;
    while (n--) {

        cin >> s;
        int len = s.size();
        int sum = 0;
        bool is_odd = false;

        for (int i = len - 1; i >= 0; i--) {
            if (!is_odd) {
                sum = sum + (s[i] - '0');
                is_odd = true;
            } else {
                sum = sum + handle(s[i]);
                is_odd = false;
            }
        }

        if (sum % 10 == 0) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }

    }

    return 0;
}
