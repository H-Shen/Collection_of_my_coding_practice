#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 200005;
int A[MAXN];
int temp[MAXN];
ll counter = 0;

// sort A[l ... r-1]
void merge(int l, int r) {
    if (l >= r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    merge(l, mid);
    merge(mid, r);
    int p = l;
    int q = mid;
    int s = l;
    while (s < r) {
        if (p >= mid || (q < r && A[p] > A[q]) ) {
            temp[s++] = A[q++];
            counter += static_cast<ll>(mid - p);
        } else {
            temp[s++] = A[p++];
        }
    }
    for (int i = l; i < r; ++i) {
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
        putchar('\n');
    }
}

int main() {

    int t, n;
    IO::read(t);
    while (t--) {
        IO::read(n);
        for (int i = 0; i < n; ++i) {
            IO::read(A[i]);
        }
        merge(0, n);
        IO::writeln(counter);
        counter = 0;
        memset(temp, 0, sizeof(int) * MAXN);
    }

    return 0;
}
