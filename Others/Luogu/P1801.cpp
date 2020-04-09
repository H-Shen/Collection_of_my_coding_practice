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
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct Node {
    ll val;
    int id;
    bool operator < (const Node &obj) const {
        if (val == obj.val) {
            return id < obj.id;
        }
        return val < obj.val;
    }
    explicit Node(ll val, int id) : val(val), id(id) {}
    Node() = default;
};
using RBTree = tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
RBTree T;

int main() {

    int m, n;
    ll val;
    IO::read(m, n);
    deque<Node> A(m);
    for (int i = 0; i < m; ++i) {
        IO::read(val);
        A.at(i) = Node(val, i);
    }
    deque<size_t> B(n);
    for (int i = 0; i < n; ++i) {
        IO::read(B.at(i));
    }
    int counter = 0;
    size_t current_size;
    while (!B.empty()) {
        current_size = B.front();
        B.pop_front();
        while (true) {
            if (T.size() == current_size) {
                break;
            }
            T.insert(A.front());
            A.pop_front();
        }
        ++counter;
        IO::writeln(T.find_by_order(counter - 1)->val);
    }

    return 0;
}
