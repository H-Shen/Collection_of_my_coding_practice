// https://open.kattis.com/problems/beehives
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
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

struct Node {
    double x, y;
    bool fight = false;
};

int main() {

    double d;
    int n;
    while (true) {
        scanf("%lf %d", &d, &n);
        if (sgn(d) == 0 && n == 0) {
            break;
        }
        vector<Node> A(n);
        for (auto &i : A) {
            scanf("%lf %lf", &i.x, &i.y);
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ( sgn(sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x) + (A[i].y-A[j].y)*(A[i].y-A[j].y)) - d) < 0 ) {
                    A[i].fight = true;
                    A[j].fight = true;
                }
            }
        }
        int sour = 0;
        int sweet = 0;
        for (const auto &i : A) {
            if (i.fight) {
                ++sour;
            } else {
                ++sweet;
            }
        }
        printf("%d sour, %d sweet\n", sour, sweet);
    }

    return 0;
}
