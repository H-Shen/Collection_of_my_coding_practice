#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using RBTree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

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

typedef unsigned int ui;
ui last = 7;
ui seed;
ui m;
inline static
ui randNum() {
    seed = seed * 17 + last;
    return seed % m + 1;
}

struct Node {
    ui accept;
    ui time;
    ui id;
    explicit Node(ui accept, ui time, ui id) : accept(accept), time(time), id(id) {}
    Node() = default;
    bool operator<(const Node &other) const {
        if (accept == other.accept) {
            if (time == other.time) {
                return id < other.id;
            }
            return time < other.time;
        }
        return accept > other.accept;
    }
};

constexpr int MAXN = 100005;
RBTree<Node> T;
array<Node, MAXN> nodes;

int main() {

    int t, n;
    ui Ria, Rib;
    IO::read(t);
    Node node;
    node.accept = 0;
    node.time = 0;
    while (t--) {
        IO::read(m, n, seed);
        for (ui id = 1; id <= m; ++id) {
            node.id = id;
            T.insert(node);
            nodes.at(id) = node;
        }
        while (n--) {
            Ria = randNum();
            Rib = randNum();
            T.erase(nodes.at(Ria));
            nodes.at(Ria).time += Rib;
            ++nodes.at(Ria).accept;
            T.insert(nodes.at(Ria));
            last = T.order_of_key(Node(nodes.at(Ria).accept, nodes.at(Ria).time, 0));
            IO::writeln(last);
        }
        T.clear();
    }

    return 0;
}