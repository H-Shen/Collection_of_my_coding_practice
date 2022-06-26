// https://open.kattis.com/problems/morsecodepalindromes

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unordered_map<char, string> um;
    um['A'] = "01";
    um['B'] = "1000";
    um['C'] = "1010";
    um['D'] = "100";
    um['E'] = "0";
    um['F'] = "0010";
    um['G'] = "110";
    um['H'] = "0000";
    um['I'] = "00";
    um['J'] = "0111";
    um['K'] = "101";
    um['L'] = "0100";
    um['M'] = "11";
    um['N'] = "10";
    um['O'] = "111";
    um['P'] = "0110";
    um['Q'] = "1101";
    um['R'] = "010";
    um['S'] = "000";
    um['T'] = "1";
    um['U'] = "001";
    um['V'] = "0001";
    um['W'] = "011";
    um['X'] = "1001";
    um['Y'] = "1011";
    um['Z'] = "1100";
    um['0'] = "11111";
    um['1'] = "01111";
    um['2'] = "00111";
    um['3'] = "00011";
    um['4'] = "00001";
    um['5'] = "00000";
    um['6'] = "10000";
    um['7'] = "11000";
    um['8'] = "11100";
    um['9'] = "11110";
    string s;
    getline(cin, s);
    string str;
    for (auto& ch : s) {
        if (isdigit(ch) || isalpha(ch)) {
            str += um[(char)toupper(ch)];
        }
    }
    if (str.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    string str2(str);
    reverse(str2.begin(), str2.end());
    if (str2 == str) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}
