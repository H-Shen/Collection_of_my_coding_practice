#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

struct Node {
    int a, b;
    explicit Node(int a, int b) : a(a), b(b) {
        if (this->a == 0) {
            this->b = 1;
        } else {
            int temp = gcd(this->a, this->b);
            this->a /= temp;
            this->b /= temp;
        }
    }
    void output() const {
        IO::write(a);
        putchar_unlocked('/');
        IO::write(b);
        putchar_unlocked('\n');
    }
    bool operator == (const Node &other) const {
        return a == other.a && b == other.b;
    }
    bool operator < (const Node &other) const {
        return a * other.b - b * other.a < 0;
    }
};

struct my_hash_func {
    size_t operator ()(const Node &obj) const {
        return hash<int>()(obj.a) ^ hash<int>()(obj.b);
    }
};

unordered_set<Node, my_hash_func> unset;

int main() {

    int n;
    IO::read(n);
    for (int a = 1; a <= n; ++a) {
        for (int b = 0; b <= a; ++b) {
            unset.insert(Node(b, a));
        }
    }
    vector<Node> output(unset.begin(), unset.end());
    sort(output.begin(), output.end());
    for (const auto &i : output) {
        i.output();
    }

    return 0;
}