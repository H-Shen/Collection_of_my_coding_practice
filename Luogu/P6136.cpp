#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAX_ID = 0x3f3f3f3f;

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
    ll val;
    int id;
    Node(ll val, int id) : val(val), id(id) {}
    Node() : Node(0, 0) {}
    bool operator<(const Node &other) const {
        if (val == other.val) {
            return (id < other.id);
        }
        return (val < other.val);
    }
};

// Define a balance tree
using T =
tree<Node, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update>;
T RBTree;
T::iterator iter;
int global_id = 1;
int n, m, opt;
ll x;
Node temp_node;
ll last = 0;
ll result = 0;
ll x_prime;

int main() {
    
    IO::read(n, m);
    for (int i = 0; i < n; ++i) {
        IO::read(x);
        temp_node.val = x;
        temp_node.id = global_id;
        RBTree.insert(temp_node);
        ++global_id;
    }
    while (m--) {
        IO::read(opt, x_prime);
        x = x_prime ^ last;
        switch (opt) {
            case 1:
                temp_node.val = x;
                temp_node.id = global_id;
                RBTree.insert(temp_node);
                ++global_id;
                break;
            case 2:
                temp_node.val = x;
                temp_node.id = 0;
                iter = RBTree.lower_bound(temp_node);
                if (iter != RBTree.end() && iter->val == x) {
                    RBTree.erase(iter);
                }
                break;
            case 3:
                temp_node.val = x;
                temp_node.id = 1;
                last = RBTree.order_of_key(temp_node) + 1;
                result ^= last;
                break;
            case 4:
                last = RBTree.find_by_order(x - 1)->val;
                result ^= last;
                break;
            case 5:
                temp_node.val = x;
                temp_node.id = 1;
                last = (--RBTree.lower_bound(temp_node))->val;
                result ^= last;
                break;
            default:
                temp_node.val = x;
                temp_node.id = MAX_ID;
                last = RBTree.upper_bound(temp_node)->val;
                result ^= last;
                break;
        }
    }
    IO::writeln(result);
    return 0;
}
