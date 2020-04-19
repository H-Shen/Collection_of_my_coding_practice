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

map<int, ll> nodeToDepth;

int main() {

    int n, root, val;
    IO::read(n, root);
    ll counter = 0;
    ll depth;
    int minVal = root;
    int maxVal = root;
    nodeToDepth[root] = counter;
    n--;
    IO::writeln(counter);
    
    while (n--) {
        IO::read(val);
        if (val < minVal) {
            depth = nodeToDepth.begin()->second + 1;
            minVal = val;
        } else if (val > maxVal) {
            depth = nodeToDepth.rbegin()->second + 1;
            maxVal = val;
        } else {
            auto it = nodeToDepth.lower_bound(val);
            auto rightBound = it->second;
            auto leftBound = (--it)->second;
            depth = max(leftBound, rightBound) + 1;
        }
        counter += depth;
        nodeToDepth[val] = depth;
        // output
        IO::writeln(counter);
    }
    return 0;
}