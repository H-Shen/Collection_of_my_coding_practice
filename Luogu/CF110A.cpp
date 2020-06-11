#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 100;
char s[MAXN];

bool is_luck_number(int x) {
    string str = to_string(x);
    for (const char &ch : str) {
        if (ch != '7' && ch != '4') {
            return false;
        }
    }
    return true;
}

int main() {

    scanf("%s", s);
    int count = 0;
    string str = s;
    for (const char &ch : str) {
        if (ch == '7' || ch == '4') {
            ++count;
        }
    }
    if (is_luck_number(count)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}