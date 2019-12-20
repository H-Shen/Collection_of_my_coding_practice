#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int convertK(ll G, ll S, ll K) {
    return 17 * 29 * G + 29 * S + K;
}

string convertGSK(ll gap) {
    ll G = gap / (17 * 29);
    ll S = (gap - 17 * 29 * G) / 29;
    ll K = gap - 17 * 29 * G - 29 * S;
    return to_string(G) + '.' + to_string(S) + '.' + to_string(K);
}

int main() {
    ll G0, S0, K0, G1, S1, K1;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &G0, &S0, &K0, &G1, &S1, &K1);
    ll gap = convertK(G1, S1, K1) - convertK(G0, S0, K0);

    if (gap < 0) {
        printf("-%s\n", convertGSK(-gap).c_str());
    } else {
        printf("%s\n", convertGSK(gap).c_str());
    }

    return 0;
}