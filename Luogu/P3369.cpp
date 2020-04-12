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
tree<Node, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update> RBTree;
        
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<int, int, custom_hash> val2counter;

int main() {

    int n, opt;
    ll x;
    Node temp_node;
    IO::read(n);
    while (n--) {
        IO::read(opt, x);
        switch (opt) {
            case 1:
                // Count from 1
                ++val2counter[x];
                RBTree.insert(Node(x, val2counter[x]));
                break;
            case 2:
                if (val2counter.find(x) != val2counter.end()) {
                    RBTree.erase(Node(x, val2counter[x]));
                    --val2counter[x];
                    if (val2counter[x] == 0) {
                        val2counter.erase(x);
                    }
                }
                break;
            case 3:
                if (val2counter.find(x) == val2counter.end()) {
                    temp_node.val = x;
                    temp_node.id = 1;
                    RBTree.insert(temp_node);
                    IO::writeln(RBTree.order_of_key(temp_node) + 1);
                    RBTree.erase(temp_node);
                } else {
                    temp_node.val = x;
                    temp_node.id = 1;
                    IO::writeln(RBTree.order_of_key(temp_node) + 1);
                }
                break;
            case 4:
                IO::writeln(RBTree.find_by_order(x - 1)->val);
                break;
            case 5:
                if (val2counter.find(x) == val2counter.end()) {
                    temp_node.val = x;
                    temp_node.id = 1;
                    RBTree.insert(temp_node);
                    IO::writeln((--RBTree.lower_bound(temp_node))->val);
                    RBTree.erase(temp_node);
                } else {
                    temp_node.val = x;
                    temp_node.id = 1;
                    IO::writeln((--RBTree.lower_bound(temp_node))->val);
                }
                break;
            default:
                if (val2counter.find(x) == val2counter.end()) {
                    temp_node.val = x;
                    temp_node.id = 1;
                    RBTree.insert(temp_node);
                    IO::writeln(RBTree.upper_bound(temp_node)->val);
                    RBTree.erase(temp_node);
                } else {
                    temp_node.val = x;
                    temp_node.id = val2counter[x];
                    IO::writeln(RBTree.upper_bound(temp_node)->val);
                }
                break;
        }
    }

    return 0;
}