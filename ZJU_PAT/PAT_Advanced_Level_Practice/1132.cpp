#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    ll a;
    string s;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &a);
        s = to_string(a);
        ll tmp = stol(s.substr(0, s.size() / 2)) * stol(s.substr(s.size() / 2));
        if (tmp == 0) {
            printf("No\n");
        } else if (a % tmp == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}