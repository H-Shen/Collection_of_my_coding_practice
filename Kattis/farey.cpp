// https://open.kattis.com/problems/farey
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T>
inline
void read(T& t) {
    int n = 0; int c = getchar(); t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (n) t = -t;
}
template <typename T, typename... Args>
inline
void read(T& t, Args&... args) {
    read(t); read(args...);
}
template <typename T>
inline void write(T x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
    write(x);
    puts("");
}

constexpr ll MAXN = 10005;

namespace EulerPhi {

    ll PHI[MAXN];
    void init(){
        PHI[1] = 1;
        for(ll i = 2; i < MAXN ; i++) {
            PHI[i] = i;
        }
        for(ll i = 2; i < MAXN ; i++) {
            if (PHI[i] == i)
                for (ll j = i; j < MAXN; j += i) {
                    PHI[j] = PHI[j] / i * (i - 1);
                }
        }
        PHI[1] = 2;
    }
}

// PHI[1]=2 : 0/1, 1/1
// PHI[2]=1 : 1/2
// PHI[3]=2 : 1/3, 2/3
// PHI[4]=2 : 1/4, 3/4
// PHI[5]=4 : 1/5, 2/5, 3/5, 4/5
// PHI[6]=2 : 1/6, 5/6
int main() {

    EulerPhi::init();
    ll prefixSum[MAXN];
    for (int i = 1; i <= MAXN - 5; ++i) {
        prefixSum[i] = prefixSum[i - 1] + EulerPhi::PHI[i];
    }
    int n, kase, index;
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(kase, index);
        write(kase);
        putchar(' ');
        write(prefixSum[index]);
        puts("");
    }

    return 0;
}
