#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct Node {
    explicit Node(int val, int id) : val(val), id(id) {}
    bool operator<(const Node &rhs) const {
        if (val == rhs.val) {
            return id < rhs.id;
        }
        return val > rhs.val;
    }
    int val;
    int id;
};

using Rbtree = tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
Rbtree T;
int id = 1;

int main() {

    int m, q, c, v;
    IO::read(m, q);
    while (m--) {
        IO::read(v);
        T.insert(Node(v, id));
        ++id;
    }
    while (q--) {
        IO::read(c, v);
        if (c == 1) {
            IO::writeln(T.find_by_order(v - 1)->val);
        } else {
            T.insert(Node(v, id));
            ++id;
        }
    }
    return 0;
}