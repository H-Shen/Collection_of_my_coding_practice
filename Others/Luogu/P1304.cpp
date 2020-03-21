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

constexpr int MAXN = 10000;
vector<int> prime;
vector<bool> is_prime = {false};
auto is_prime_check = [](int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
};

auto solve = [](int n) {
    for (const auto &i : prime) {
        if (is_prime.at(n - i)) {
            printf("%d=%d+%d\n", n, i, n - i);
            return;
        }
    }
};

int main() {

    for (int i = 1; i <= MAXN; ++i) {
        if (is_prime_check(i)) {
            prime.emplace_back(i);
            is_prime.emplace_back(true);
        } else {
            is_prime.emplace_back(false);
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 4; i <= n; i += 2) {
        solve(i);
    }

    return 0;
}