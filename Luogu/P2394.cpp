#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;

constexpr int MAXN = 15;

int main() {

    string s;
    char ch;
    for (int i = 0; i < MAXN && cin >> ch; ++i) {
        s.push_back(ch);
    }
    ld ans = stold(s);
    printf("%.8Lf\n", ans / 23.0);


    return 0;
}
