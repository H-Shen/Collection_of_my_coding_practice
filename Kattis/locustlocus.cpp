// https://open.kattis.com/problems/locustlocus

#include <bits/extc++.h>

using namespace std;
using ll = long long;

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

int k;
struct Node {
    int y, c1, c2;
    Node() = default;
};
vector<Node> vec;
int start = numeric_limits<int>::max();

int main() {
    IO::read(k);
    vec.resize(k);
    for (int i = 0; i < k; ++i) {
        IO::read(vec[i].y, vec[i].c1, vec[i].c2);
        start = min(start, vec[i].y);
    }
    ++start;
    while (true) {
        for (int i = 0; i < k; ++i) {
            if (start > vec[i].y && (start-vec[i].y) % vec[i].c1 == 0 && (start-vec[i].y) % vec[i].c2 == 0) {
                IO::writeln(start);
                return 0;
            }
        }
        ++start;
    }
    return 0;
}
