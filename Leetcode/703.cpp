#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

class KthLargest {
private:
    struct Node {
        int val, index;
        explicit Node(int val, int index) : val(val), index(index) {}
        Node() = default;
        bool operator > (const Node &node) const {
            if (val == node.val) return index < node.index;
            return val > node.val;
        }
    };
    int k;
    int globalIndex;
    __gnu_pbds::tree<Node, __gnu_pbds::null_type, greater<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> RBTree;
public:
    KthLargest(int k, vector<int>& nums) : k(k), globalIndex(0) {
        for (const auto &i : nums) {
            RBTree.insert(Node(i, globalIndex++));
        }
    }
    
    int add(int val) {
        RBTree.insert(Node(val, globalIndex++));
        return RBTree.find_by_order(k - 1)->val;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */