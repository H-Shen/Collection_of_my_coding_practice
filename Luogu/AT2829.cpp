#include <cstdio>
#include <cctype>

using namespace std;
using ll = long long;

constexpr int MAXN = 100005;
ll A[MAXN];
ll temp[MAXN];
ll counter = 0;

// sort A[l ... r-1]
void merge(ll l, ll r) {
    if (l >= r - 1) {
        return;
    }
    ll mid = (l + r) / 2;
    merge(l, mid);
    merge(mid, r);
    ll p = l;
    ll q = mid;
    ll s = l;
    while (s < r) {
        if (p >= mid || (q < r && A[p] > A[q]) ) {
            temp[s++] = A[q++];
            counter += mid - p;
        } else {
            temp[s++] = A[p++];
        }
    }
    for (ll i = l; i < r; ++i) {
        A[i] = temp[i];
    }
}

namespace IO {
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
}

int main() {

    int n;
    IO::read<int>(n);
    for (int i = 0; i < n; ++i) {
        IO::read<ll>(A[i]);
    }
    merge(0, n);
    IO::writeln<ll>(counter);

    return 0;
}
