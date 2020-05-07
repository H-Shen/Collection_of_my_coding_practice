#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 256;

int A[MAXN];

int main() {

    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        ++A[s.front()];
    }
    bool haveAns = false;
    for (int i = 0; i < MAXN; ++i) {
        if (A[i] >= 5) {
            putchar_unlocked(i);
            haveAns = true;
        }
    }
    if (!haveAns) {
        fputs_unlocked("PREDAJA", stdout);
    }

    return 0;
}
