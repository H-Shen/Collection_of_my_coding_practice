// https://open.kattis.com/problems/closestpair1
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-6;

inline int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

inline const double &doubleMax(const double &l, const double &r) {
    return (sgn(l - r) >= 0) ? l : r;
}

inline const double &doubleMin(const double &l, const double &r) {
    return (sgn(l - r) >= 0) ? r : l;
}

namespace TwoDTree {
    // Default longest distance
    constexpr double MAX_DIST = 4e18;
    // Maximal nodes in the tree
    constexpr int MAX_NODES = 100005;
    // Definition of a tree node
    struct Node {
        double x, y;
    };

    // Comparators in each dimension
    inline bool cmp_by_x(const Node &l, const Node &r) {
        return (sgn(l.x - r.x) == -1);
    }

    inline bool cmp_by_y(const Node &l, const Node &r) {
        return (sgn(l.y - r.y) == -1);
    }

    int n;  // current number of nodes in the tree
    int lson[MAX_NODES]; // lson[i] = the left son of i
    int rson[MAX_NODES]; // rson[i] = the right son of i

    Node nodes[MAX_NODES];   // the array stores all nodes in the tree, node id starts from 1
    double left[MAX_NODES];  // left[i] = the minimal x-value in the sub-tree with the root 'i'
    double right[MAX_NODES]; // right[i] = the maximal x-value in the sub-tree with the root 'i'
    double up[MAX_NODES];    // up[i] = the maximal y-value in the sub-tree with root 'i'
    double down[MAX_NODES];  // down[i] = the minimal y-value in the sub-tree with root 'i'

    double closest_distance = MAX_DIST;
    // store the pair of nodes that have the closest distance to each other
    int u, v;

    // reset the tree
    inline void reset() {
        closest_distance = MAX_DIST;
        u = 1;
        v = 2;
        fill(lson + 1, lson + 1 + n, 0);
        fill(rson + 1, rson + 1 + n, 0);
        fill(left + 1, left + 1 + n, 0);
        fill(right + 1, right + 1 + n, 0);
        fill(up + 1, up + 1 + n, 0);
        fill(down + 1, down + 1 + n, 0);
    }

    // Euclidean dist of two points without square root
    inline double dist(int l, int r) {
        return (nodes[l].x - nodes[r].x) * (nodes[l].x - nodes[r].x) +
               (nodes[l].y - nodes[r].y) * (nodes[l].y - nodes[r].y);
    }

    // Update left[id], right[id], up[id], down[id]
    inline void maintain(int id) {
        left[id] = nodes[id].x;
        right[id] = nodes[id].x;
        up[id] = nodes[id].y;
        down[id] = nodes[id].y;
        // Check if it has left/right child, make sure the range of id contains the range of its children
        if (lson[id] != 0) {
            left[id] = doubleMin(left[id], left[lson[id]]);
            right[id] = doubleMax(right[id], right[lson[id]]);
            down[id] = doubleMin(down[id], down[lson[id]]);
            up[id] = doubleMax(up[id], up[lson[id]]);
        }
        if (rson[id] != 0) {
            left[id] = doubleMin(left[id], left[rson[id]]);
            right[id] = doubleMax(right[id], right[rson[id]]);
            down[id] = doubleMin(down[id], down[rson[id]]);
            up[id] = doubleMax(up[id], up[rson[id]]);
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

    // the Euclidean distance without square root from node 'a' to the subtree with root 'b' which is represented by a rectangle
    double dist_to_tree(int a, int b) {
        double distance = 0.0;
        if (sgn(nodes[a].x - left[b]) == -1) {
            distance += (nodes[a].x - left[b]) * (nodes[a].x - left[b]);
        }
        if (sgn(nodes[a].x - right[b]) == 1) {
            distance += (nodes[a].x - right[b]) * (nodes[a].x - right[b]);
        }
        if (sgn(nodes[a].y - up[b]) == 1) {
            distance += (nodes[a].y - up[b]) * (nodes[a].y - up[b]);
        }
        if (sgn(nodes[a].y - down[b]) == -1) {
            distance += (nodes[a].y - down[b]) * (nodes[a].y - down[b]);
        }
        return distance;
    }

    // Query the closest distance from id to some node in the range [l, r] and store in 'closest_distance'
    void query(int l, int r, int id) {
        // Base case:
        if (l > r) {
            return;
        }
        int mid = (l + r) >> 1;
        if (mid != id) {
            double temp = dist(mid, id);
            if (sgn(closest_distance - temp) > 0) {
                closest_distance = temp;
                u = mid;
                v = id;
            }
        }
        // Base case:
        if (l == r) {
            return;
        }
        double dist_to_left_subtree = dist_to_tree(id, lson[mid]);
        double dist_to_right_subtree = dist_to_tree(id, rson[mid]);
        int sgn0 = sgn(closest_distance - dist_to_left_subtree);
        int sgn1 = sgn(closest_distance - dist_to_right_subtree);
        // Recursively call the func if closest_distance is not actually the 'closest'
        if (sgn0 == 1 && sgn1 == 1) {
            // We choose the smallest dist to the subtree first to avoid one recursive call
            if (sgn(dist_to_left_subtree - dist_to_right_subtree) == -1) {
                query(l, mid - 1, id);
                // We do the recursion to the right subtree if closest_distance is still larger than its dist to the right_subtree
                if (sgn(closest_distance - dist_to_right_subtree) == 1) {
                    query(mid + 1, r, id);
                }
            } else {
                query(mid + 1, r, id);
                // We do the recursion to the left subtree if closest_distance is still larger than its dist to the left_subtree
                if (sgn(closest_distance - dist_to_left_subtree) == 1) {
                    query(l, mid - 1, id);
                }
            }
        } else {
            // We do the recursion to the left subtree if closest_distance is still larger than its dist to the left_subtree
            if (sgn(closest_distance - dist_to_left_subtree) == 1) {
                query(l, mid - 1, id);
            }
            // We do the recursion to the right subtree if closest_distance is still larger than its dist to the right_subtree
            if (sgn(closest_distance - dist_to_right_subtree) == 1) {
                query(mid + 1, r, id);
            }
        }
    }
}

int main() {

    while (true) {
        scanf("%d", &TwoDTree::n);
        if (TwoDTree::n == 0) break;
        // read the nodes
        for (int i = 1; i <= TwoDTree::n; ++i) {
            scanf("%lf %lf", &TwoDTree::nodes[i].x, &TwoDTree::nodes[i].y);
        }
        // build the tree
        TwoDTree::build(1, TwoDTree::n);
        // update 'closest_distance' by checking the closest distance of each node in the whole tree
        for (int i = 1; i <= TwoDTree::n; ++i) {
            TwoDTree::query(1, TwoDTree::n, i);
        }
        // output
        if (TwoDTree::u > TwoDTree::v) {
            swap(TwoDTree::u, TwoDTree::v);
        }
        printf("%.2lf %.2lf %.2lf %.2lf\n", TwoDTree::nodes[TwoDTree::u].x, TwoDTree::nodes[TwoDTree::u].y, TwoDTree::nodes[TwoDTree::v].x, TwoDTree::nodes[TwoDTree::v].y);
        // reset
        TwoDTree::reset();
    }
    return 0;
}
