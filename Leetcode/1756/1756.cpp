#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

struct Node {
    int val, time;
    Node(int val, int time) : val(val), time(time) {}
    bool operator < (const Node &obj) const {
        return time < obj.time;
    }
};

using RBTree = __gnu_pbds::tree<Node, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

class MRUQueue {
private:
    RBTree rbtree;
    int timestamp;
public:
    MRUQueue(int n) {
        timestamp = 1;
        for (int i = 1; i <= n; ++i) {
            rbtree.insert(Node(i,timestamp));
            ++timestamp;
        }
    }
    
    int fetch(int k) {
        auto iter = rbtree.find_by_order(k-1);
        int val = iter->val;
        int time = iter->time;
        rbtree.erase(iter);
        rbtree.insert(Node(val, timestamp));
        ++timestamp;
        return val;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */