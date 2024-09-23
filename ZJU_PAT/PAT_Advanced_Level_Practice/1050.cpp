#include <bits/stdc++.h>


using namespace std;
using ll = long long;
const int MAXN = 10005;
char s[MAXN];

int main() {
    string s0, s1, res;

    scanf("%[^\n]", s);
    getchar();
    s0 = s;

    scanf("%[^\n]", s);
    getchar();
    s1 = s;

    unordered_set<char> dict(s1.begin(), s1.end());
    for (const auto &p : s0) {
        if (dict.find(p) == dict.end()) {
            res += p;
        }
    }
    printf("%s\n", res.c_str());
    return 0;
}