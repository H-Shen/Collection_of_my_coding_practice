#include <bits/extc++.h>

using namespace std;
using ll = long long;

template<typename T>
using RBTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

struct Node {
    int val;
    int id;
    Node() = default;
    Node(int val, int id) : val(val), id(id){}
    bool operator < (const Node &node) const {
        if (val == node.val) {
            return id < node.id;
        }
        return val < node.val;
    }
};

int n;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vec.resize(n);
    for (auto&i : vec) cin >> i;
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    RBTree<Node> left, right;
    // add nodes in the right RBT
    for (int k = 1; k < n; ++k) {
        right.insert(Node(vec[k], k));
    }
    ll tot = 0;
    ll lcount, rcount;
    for (int j = 1; j < n-1; ++j) {
        left.insert(Node(vec[j-1], j-1));
        right.erase(Node(vec[j], j));
        lcount = (ll)left.order_of_key(Node(vec[j], INT_MIN));
        rcount = (ll)(right.size() - (right.order_of_key(Node(vec[j], INT_MAX))));
        // cout << left.order_of_key(Node(vec[j], INT_MIN)) << ' ' << right.size() - (right.order_of_key(Node(vec[j], INT_MAX))) << '\n';
        tot += lcount * rcount;
    }
    cout << tot << '\n';
    return 0;
}