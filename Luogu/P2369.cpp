#include <bits/extc++.h>

using namespace std;
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

priority_queue<int> pq;
priority_queue<int, vector<int>, greater<> > pq_output;
int n, m, val;

int main() {

    IO::read(n, m);
    if (n == 0 || m == 0) {
        return 0;
    }
    while (n--) {
        IO::read(val);
        if (pq.size() < m) {
            pq.push(val);
        } else if (val < pq.top()) {
            pq.pop();
            pq.push(val);
        }
    }
    while (!pq.empty()) {
        pq_output.push(pq.top());
        pq.pop();
    }
    while (!pq_output.empty()) {
        IO::writeln(pq_output.top());
        pq_output.pop();
    }
    return 0;
}
