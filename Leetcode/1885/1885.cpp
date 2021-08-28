#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using ll = long long;

struct Node {
    int val, id;
    Node(int val, int id) : val(val), id(id){}
    Node() = default;
    bool operator < (const Node &node) const {
        if (val == node.val) {
            return id < node.id;
        }
        return val < node.val;
    }
};
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        // nums1[i] + nums1[j] > nums2[i] + nums2[j] (i<j)
        // nums1[i] - nums2[i] > nums2[j] - nums1[j] (i<j)
        // nums2[i] - nums1[i] < nums1[j] - nums2[j] (i<j)
        // A[i]<B[j] (i<j)
        int n = (int)nums1.size();
        if (n == 1) {
            return 0;
        }
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = nums2[i]-nums1[i];
        }
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            B[i] = nums1[i]-nums2[i];
        }
        ll counter = 0;
        int id = 0;
        tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
        int minA = numeric_limits<int>::max();
        for (int i = 1; i < n; ++i) {
            rbtree.insert(Node(A[i-1], id));
            minA = min(minA, A[i-1]);
            ++id;
            if (B[i] > minA) {
                counter += (ll)(rbtree.order_of_key(Node(B[i],-1)));
            }
        }
        return counter;
    }
};