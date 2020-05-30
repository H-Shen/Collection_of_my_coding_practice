#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {

    ll s;
    scanf("%lld", &s);
    __int128 o = s;
    __int128 answer;
    answer = (o <= 0) ? 0 : (2 * o - 1);
    printf("%llu\n", static_cast<ull>(answer));

    return 0;
}