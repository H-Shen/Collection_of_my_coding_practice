#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

class MedianFinder {
private:
    struct Node {
        int val, timestamp;
        Node(int val, int timestamp) : val(val), timestamp(timestamp) {}
        bool operator < (const Node &node) const {
            if (val == node.val) return timestamp < node.timestamp;
            return val < node.val;
        }
    };
    __gnu_pbds::tree<Node, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> RBTree;
    int timestamp;
public:
    /** initialize your data structure here. */
    MedianFinder() : timestamp(0) {

    }

    void addNum(int num) {
        RBTree.insert({num, timestamp});
        ++timestamp;
    }

    double findMedian() {
        assert(!RBTree.empty());
        int n = (int)RBTree.size();
        if (n % 2 == 0) {
            return (RBTree.find_by_order(n >> 1)->val + RBTree.find_by_order((n >> 1) - 1)->val) / 2.0;
        }
        return RBTree.find_by_order(n >> 1)->val;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */