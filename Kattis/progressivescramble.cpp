// https://open.kattis.com/problems/progressivescramble
//
#include<bits/stdc++.h>

using namespace std;

unordered_map<char, int> A;
unordered_map<int, char> A_rev;

void pre() {
    A[' '] = 0;
    A_rev[0] = ' ';
    char ch = 'a';
    for (int i = 1; i <= 26; ++i) {
        A[ch] = i;
        A_rev[i] = ch;
        ++ch;
    }
}

string convert(const string &s) {
    vector<int> temp;
    for (size_t i = 0; i != s.size(); ++i) {
        if (i == 0) {
            temp.emplace_back(A[s.at(i)]);
        } else {
            temp.emplace_back(A[s.at(i)] + temp.back());
        }
    }
    string ret;
    for (const auto &i : temp) {
        ret.push_back(A_rev[i % 27]);
    }
    return ret;
}

string rev_convert(const string &s) {
    string ret;
    vector<int> temp;
    for (const auto &i : s) {
        temp.emplace_back(A[i]);
    }
    vector<int> temp_mod = {temp.front()};
    int length = static_cast<int>(temp.size());
    int k, m, b, a;
    for (int i = 1; i < length; ++i) {
        k = temp.at(i);
        m = 0;
        a = temp_mod.at(i - 1);
        while (true) {
            b = 27*m + k;
            if (b >= a && b <= 26 + a) {
                temp_mod.emplace_back(b);
                break;
            } else {
                ++m;
            }
        }
    }
    for (int i = length - 1; i >= 1; --i) {
        temp_mod.at(i) = temp_mod.at(i) - temp_mod.at(i - 1);
    }
    for (const auto &i : temp_mod) {
        ret.push_back(A_rev[i]);
    }
    return ret;
}

constexpr int maxn = 200;
char s[maxn];

int main() {

    pre();
    int n;
    char operation;
    char unused;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%c%c%[^\n]", &operation, &unused, s);
        getchar();
        if (operation == 'e') {
            printf("%s\n", convert(s).c_str());
        } else {
            printf("%s\n", rev_convert(s).c_str());
        }
    }

    return 0;
}
