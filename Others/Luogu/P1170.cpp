#include <bits/extc++.h>

using namespace std;

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

    int n, x, y, x_, y_;
    read(n);
    while (n--) {
        read(x, y, x_, y_);
        if (__gcd(abs(x - x_),  abs(y - y_)) == 1) {
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }
    return 0;
}
