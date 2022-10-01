#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using ll = long long;
using namespace __gnu_pbds;

struct Node {
    int val;
    int id;
    Node() = default;
    Node(int val, int id) : val(val), id(id) {}
    bool operator < (const Node &other) const {
        if (val == other.val) {
            return id < other.id;
        }
        return val < other.val;
    }
};

class Solution {
private:
    int id;
    tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> t;
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        id = 0;
        t.clear();
        ll cnt = 0;
        int n = (int)nums1.size();
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = nums1[i] - nums2[i];
        }
        t.insert(Node(vec[0], id));
        for (int j = 1; j < n; ++j) {
            ++id;
            cnt += (ll)(t.order_of_key(Node(vec[j]+diff,id)));
            t.insert(Node(vec[j], id));
        }
        return cnt;
    }
};