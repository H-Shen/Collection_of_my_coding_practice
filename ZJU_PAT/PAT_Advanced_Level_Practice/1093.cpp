#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1000000007;
constexpr int MAXN = 100005;
char s[MAXN];

int main() {
    ll countT = 0, countAT = 0, countPAT = 0;
    string str;
    scanf("%s", s);
    str = s;
    int len = str.size();
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] == 'T') ++countT;
        else if (str[i] == 'A') countAT = (countAT + countT) % mod;
        else countPAT = (countAT + countPAT) % mod;
    }

    printf("%lld\n", countPAT);
    return 0;
}