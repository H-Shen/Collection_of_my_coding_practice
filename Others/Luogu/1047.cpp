#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

int main() {

    int l, m, left, right;
    scanf("%d %d", &l, &m);
    vector<bool> A(l + 1, true);
    while (m--) {
        scanf("%d %d", &left, &right);
        if (left > right) {
            swap(left, right);
        }
        for (int i = left; i <= right; ++i) {
            A.at(i) = false;
        }
    }
    int counter = 0;
    for (int i = 0; i < l + 1; ++i) {
        if (A.at(i)) {
            ++counter;
        }
    }
    printf("%d\n", counter);
    return 0;
}