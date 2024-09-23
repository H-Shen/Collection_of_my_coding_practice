#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
char s[maxn];

int main() {
    string a = "PATest";
    unordered_map<char, int> dict;

    for (const auto &i : a) {
        dict[i] = 0;
    }

    string b, c;
    scanf("%s", s);
    b = s;

    for (const auto &i : b) {
        if (dict.find(i) != dict.end()) {
            ++dict[i];
        }
    }

    while (!dict.empty()) {
        for (const auto &i : a) {
            if (dict[i] == 0) {
                dict.erase(i);
            }
            if (dict.find(i) != dict.end()) {
                c += i;
                --dict[i];
                if (dict[i] == 0) {
                    dict.erase(i);
                }
            }
        }
    }
    printf("%s\n", c.c_str());
    return 0;
}