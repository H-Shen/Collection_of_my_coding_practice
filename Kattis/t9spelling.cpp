// https://open.kattis.com/problems/t9spelling
//
#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> char2map;

unordered_map<char, string> A = {
        {'a', "2"},
        {'b', "22"},
        {'c', "222"},
        {'d', "3"},
        {'e', "33"},
        {'f', "333"},
        {'g', "4"},
        {'h', "44"},
        {'i', "444"},
        {'j', "5"},
        {'k', "55"},
        {'l', "555"},
        {'m', "6"},
        {'n', "66"},
        {'o', "666"},
        {'p', "7"},
        {'q', "77"},
        {'r', "777"},
        {'s', "7777"},
        {'t', "8"},
        {'u', "88"},
        {'v', "888"},
        {'w', "9"},
        {'x', "99"},
        {'y', "999"},
        {'z', "9999"},
        {' ', "0"}
};

int main() {

    // pre
    string tempStr;
    tempStr = "abc";
    for (const char &i : tempStr) {
        char2map[i] = 2;
    }
    tempStr = "def";
    for (const char &i : tempStr) {
        char2map[i] = 3;
    }
    tempStr = "ghi";
    for (const char &i : tempStr) {
        char2map[i] = 4;
    }
    tempStr = "jkl";
    for (const char &i : tempStr) {
        char2map[i] = 5;
    }
    tempStr = "mno";
    for (const char &i : tempStr) {
        char2map[i] = 6;
    }
    tempStr = "pqrs";
    for (const char &i : tempStr) {
        char2map[i] = 7;
    }
    tempStr = "tuv";
    for (const char &i : tempStr) {
        char2map[i] = 8;
    }
    tempStr = "wxyz";
    for (const char &i : tempStr) {
        char2map[i] = 9;
    }
    char2map[' '] = 0;

    // input
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.get();
    string s;
    char lastChar;
    for (int i = 1; i <= n; ++i) {
        getline(cin, s);
        cout << "Case #" << i << ": ";
        lastChar = '\0';
        for (const char &ch : s) {
            if (lastChar == '\0') {
                lastChar = ch;
            } else {
                if (char2map[ch] == char2map[lastChar]) {
                    cout << ' ';
                } else {
                    lastChar = ch;
                }
            }
            cout << A[ch];
        }
        cout << endl;
    }


    return 0;
}
