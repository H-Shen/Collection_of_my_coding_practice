// https://open.kattis.com/problems/runlengthencodingrun

#include<bits/stdc++.h>

using namespace std;

inline
string encode(const string &s) {
    string res;
    char lastChar = '\0';
    int count = 0;
    for (const auto &ch : s) {
        if (lastChar == '\0') {
            lastChar = ch;
            ++count;
            continue;
        }
        if (ch != lastChar) {
            res = res + lastChar + to_string(count);
            lastChar = ch;
            count = 1;
        } else {
            ++count;
        }
    }
    if (count != 0) {
        res = res + lastChar + to_string(count);
    }
    return res;
}

inline
string decode(const string &s) {
    string res;
    char lastChar = '\0';
    string count;
    for (const auto &ch : s) {
        if (lastChar == '\0') {
            lastChar = ch;
            continue;
        }
        if (ch >= '0' && ch <= '9') {
            count = count + ch;
        } else {

            res = res + string(stoi(count), lastChar);
            count = "";
            lastChar = ch;
        }
    }

    if (count != "") {
        res = res + string(stoi(count), lastChar);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if (a == "E") {
        cout << encode(b) << endl;
    } else {
        cout << decode(b) << endl;
    }

    return 0;
}
