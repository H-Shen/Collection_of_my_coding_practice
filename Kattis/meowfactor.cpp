// https://open.kattis.com/problems/meowfactor
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAX_BASE = 130;
vector<__int128> A;

void pre() {
    for (int i = MAX_BASE; i >= 1; --i) {
        __int128 sum = 1;
        for (int j = 1; j <= 9; ++j) {
            sum *= i;
        }
        A.emplace_back(sum);
    }
}

int main() {

    pre();
    long long n;
    scanf("%lld", &n);
    __int128 n_(n);
    for (size_t i = 0; i != A.size(); ++i) {
        if (n_ % A.at(i) == 0) {
            printf("%d\n", MAX_BASE - static_cast<int>(i));
            break;
        }
    }

    return 0;
}
