#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr double EPS = 1e-6;

inline constexpr static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

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

namespace TwoDTree {
    // Maximal nodes in the tree
    constexpr int MAX_NODES = 100005;
    // Definition of a tree node
    struct Node {
        ll x, y;
    };

    // Comparators in each dimension
    inline bool cmp_by_x(const Node &l, const Node &r) {
        return l.x < r.x;
    }

    inline bool cmp_by_y(const Node &l, const Node &r) {
        return l.y < r.y;
    }

    priority_queue<ll, vector<ll>, greater<> > pq;  // store the kth longest distance to 1st longest distance

    int n;  // current number of nodes in the tree
    int lson[MAX_NODES]; // lson[i] = the left son of i
    int rson[MAX_NODES]; // rson[i] = the right son of i

    Node nodes[MAX_NODES];   // the array stores all nodes in the tree, node id starts from 1
    ll left[MAX_NODES];  // left[i] = the minimal x-value in the sub-tree with the root 'i'
    ll right[MAX_NODES]; // right[i] = the maximal x-value in the sub-tree with the root 'i'
    ll up[MAX_NODES];    // up[i] = the maximal y-value in the sub-tree with root 'i'
    ll down[MAX_NODES];  // down[i] = the minimal y-value in the sub-tree with root 'i'

    // Update left[id], right[id], up[id], down[id]
    inline void maintain(int id) {
        left[id] = nodes[id].x;
        right[id] = nodes[id].x;
        up[id] = nodes[id].y;
        down[id] = nodes[id].y;
        // Check if it has left/right child, make sure the range of id contains the range of its children
        if (lson[id] != 0) {
            left[id] = min(left[id], left[lson[id]]);
            right[id] = max(right[id], right[lson[id]]);
            down[id] = min(down[id], down[lson[id]]);
            up[id] = max(up[id], up[lson[id]]);
        }
        if (rson[id] != 0) {
            left[id] = min(left[id], left[rson[id]]);
            right[id] = max(right[id], right[rson[id]]);
            down[id] = min(down[id], down[rson[id]]);
            up[id] = max(up[id], up[rson[id]]);
        }
    }

    // Build the tree with all nodes from node id = l to node id = r, return (l + r) / 2
    inline int build(int l, int r) {
        // Base case:
        if (l > r) {
            return 0;
        }
        int mid = (l + r) >> 1;
        double average_x = 0.0;
        double average_y = 0.0;
        for (int i = l; i <= r; ++i) {
            average_x += nodes[i].x;
            average_y += nodes[i].y;
        }
        average_x /= (r - l + 1);
        average_y /= (r - l + 1);
        double average_variance_x = 0.0;
        double average_variance_y = 0.0;
        for (int i = l; i <= r; ++i) {
            average_variance_x +=
                    (nodes[i].x - average_x) * (nodes[i].x - average_x);
            average_variance_y +=
                    (nodes[i].y - average_y) * (nodes[i].y - average_y);
        }
        // We don't choose the dimension alternatively, instead, we choose the dimension that has larger average variance
        if (sgn(average_variance_x - average_variance_y) >= 0) {
            nth_element(nodes + l, nodes + mid, nodes + r + 1, cmp_by_x);
        } else {
            nth_element(nodes + l, nodes + mid, nodes + r + 1, cmp_by_y);
        }
        // Recursively insert the nodes other than 'mid'
        lson[mid] = build(l, mid - 1);
        rson[mid] = build(mid + 1, r);
        // Update left[], right[], up[], down[] after we insert a node
        maintain(mid);
        return mid;
    }

    inline ll square(const ll &x) {
        return x * x;
    }

    // the longest Euclidean distance without square root from node 'a' to the subtree with root 'b' which is represented by a rectangle
    inline ll dist_to_tree(int a, int b) {
        ll dist_x = max(square(nodes[a].x - left[b]),
                        square(nodes[a].x - right[b]));
        ll dist_y = max(square(nodes[a].y - up[b]),
                        square(nodes[a].y - down[b]));
        return dist_x + dist_y;
    }

    // Query the longest distance from id to some node in the range [l, r] and store it in the heap
    inline void query(int l, int r, int id) {
        // Base case:
        if (l > r) {
            return;
        }
        int mid = (l + r) >> 1;
        ll current_distance = square(nodes[mid].x - nodes[id].x) +
                              square(nodes[mid].y - nodes[id].y);
        if (current_distance > pq.top()) {
            pq.pop();
            pq.push(current_distance);
        }

        ll dist_to_left_subtree = dist_to_tree(id, lson[mid]);
        ll dist_to_right_subtree = dist_to_tree(id, rson[mid]);
        if (pq.top() < dist_to_left_subtree &&
            pq.top() < dist_to_right_subtree) {
            if (dist_to_left_subtree > dist_to_right_subtree) {
                query(l, mid - 1, id);
                if (dist_to_right_subtree > pq.top()) {
                    query(mid + 1, r, id);
                }
            } else {
                query(mid + 1, r, id);
                if (dist_to_left_subtree > pq.top()) {
                    query(l, mid - 1, id);
                }
            }
        } else {
            if (dist_to_left_subtree > pq.top()) {
                query(l, mid - 1, id);
            }
            if (dist_to_right_subtree > pq.top()) {
                query(mid + 1, r, id);
            }
        }
    }
}

int main() {

    int k;
    IO::read(TwoDTree::n, k);
    k <<= 1;
    for (int i = 0; i < k; ++i) {
        TwoDTree::pq.push(0);
    }
    for (int i = 1; i <= TwoDTree::n; ++i) {
        IO::read(TwoDTree::nodes[i].x, TwoDTree::nodes[i].y);
    }
    TwoDTree::build(1, TwoDTree::n);
    for (int i = 1; i <= TwoDTree::n; ++i) {
        TwoDTree::query(1, TwoDTree::n, i);
    }
    IO::writeln(TwoDTree::pq.top());

    return 0;
}