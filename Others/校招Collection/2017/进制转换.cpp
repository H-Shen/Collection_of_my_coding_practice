// https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, string> baseStr = {{10, "A"},
                                      {11, "B"},
                                      {12, "C"},
                                      {13, "D"},
                                      {14, "E"},
                                      {15, "F"},
                                      {16, "G"},
                                      {17, "H"},
                                      {18, "I"},
                                      {19, "J"},
                                      {20, "K"},
                                      {21, "L"},
                                      {22, "M"},
                                      {23, "N"},
                                      {24, "O"},
                                      {25, "P"},
                                      {26, "Q"},
                                      {27, "R"},
                                      {28, "S"},
                                      {29, "T"},
                                      {30, "U"},
                                      {31, "V"},
                                      {32, "W"},
                                      {33, "X"},
                                      {34, "Y"},
                                      {35, "Z"}};

string decimalToAny(int num, int n) {
    bool flag = true;
    if (num < 0) {
        num = -num;
        flag = false;
    }

    string new_num_str = "";
    string remainder_string;
    int remainder;

    while (num != 0) {
        remainder = num % n;
        if (remainder > 9 && remainder < 36) {
            remainder_string = baseStr[remainder];
        } else {
            stringstream tmp;
            tmp << remainder;
            tmp >> remainder_string;
        }
        new_num_str = remainder_string + new_num_str;
        num /= n;
    }

    if (flag) {
        return new_num_str;
    } else {
        new_num_str = "-" + new_num_str;
        return new_num_str;
    }
}

string baseMToBaseN(string M, int m, int n) {
    const char *p = M.c_str();
    int decimal = strtol(p, NULL, m);

    if (decimal == 0)
        return "0";

    return decimalToAny(decimal, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    int m, n;
    while (cin >> m >> n) {
        cout << decimalToAny(m, n) << endl;
    }
    return 0;
}