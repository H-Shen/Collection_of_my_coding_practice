// https://open.kattis.com/problems/kleptography
//
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, char> convert;
unordered_map<char, int> rev_convert;

void pre() {
    int i = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        convert[i] = ch;
        rev_convert[ch] = i;
        ++i;
    }
}

int main() {

    pre();
    int n, m;
    string a, ciphertext;
    cin >> n >> m;
    cin >> a >> ciphertext;
    string plaintext(ciphertext.size(), '#');
    string key(ciphertext.size(), '#');
    auto iter0 = plaintext.rbegin();
    auto iter1 = a.rbegin();
    while (iter1 != a.rend()) {
        *iter0 = *iter1;
        ++iter0;
        ++iter1;
    }

    try {
        bool iterate = true;
        while (iterate) {
            iterate = false;
            for (int i = 0; i < m; ++i) {
                if (plaintext.at(i) != '#') {
                    int p = rev_convert[ciphertext.at(i)] + 26 -
                            rev_convert[plaintext.at(i)];
                    while (p >= 26) {
                        p -= 26;
                    }
                    key.at(i) = convert[p];
                } else {
                    iterate = true;
                }
            }
            for (int i = m - 1; i >= 0; --i) {
                if (key.at(i) != '#') {
                    plaintext.at(i - n) = key.at(i);
                }
            }
        }
    } catch (...) {}
    cout << plaintext << endl;

    return 0;
}
