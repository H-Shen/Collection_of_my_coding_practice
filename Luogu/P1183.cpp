#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using PX = complex<double>;

double cp(PX a, PX b) {return (conj(a)*b).imag();}

// points must be in CW or CCW order
double area(vector<PX> const& P) {
    double a = 0.0;
    for (size_t i = 0; i != P.size(); i++)
        a += cp(P[i], P[(i+1)%P.size()]);
    return 0.5 * fabs(a);
}

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int main() {

    int n, x, y;
    IO::read(n);
    vector<PX> A(n);
    for (int i = 0; i < n; ++i) {
        IO::read(x, y);
        A.at(i).real(x);
        A.at(i).imag(y);
    }
    IO::writeln((int)(lround(area(A))));

    return 0;
}