// https://open.kattis.com/problems/vudu
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }

    template<typename T>
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct Node {
    ll val;
    int pos;
    Node() = default;
    Node(ll val, int pos) : val(val), pos(pos) {}
    bool operator < (const Node& node) const {
        if (val == node.val) {
            return pos < node.pos;
        }
        return val < node.val;
    }
};

int n;
tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> t;
vector<ll> A;
ll p;
ll cnt;

int main() {
    IO::read(n);
    ++n;
    A.resize(n);
    for (int i = 1; i < n; ++i) IO::read(A[i]);
    // get prefix sum
    for (int i = 1; i < n; ++i) {
        A[i] += A[i-1];
    }
    IO::read(p);
    for (int i = 0; i < n; ++i) {
        A[i] -= p*i;
    }
    if (n == 1) {
        if (A[0] >= p) {
            ++cnt;
        }
        IO::writeln(cnt);
        return 0;
    }
    t.insert(Node(A[0], 0));
    for (int i = 1; i < n; ++i) {
        ll counter = (ll)t.order_of_key(Node(A[i], numeric_limits<int>::max()));
        cnt += counter;
        t.insert(Node(A[i], i));
    }
    IO::writeln(cnt);
    return 0;
}
