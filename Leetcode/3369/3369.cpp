#include <bits/extc++.h>

using ll = long long;

constexpr int MIN_ID = -0x3f3f3f3f;

struct Node {
    ll value;
    int freq;
    Node(ll value, int freq) : value(value), freq(freq) {};
    Node() = default;
    bool operator < (const Node& other) const {
        if (freq == other.freq) {
            return value < other.value;
        }
        return freq > other.freq;
    }
};

struct ModeTracker {
    unordered_map<ll, int> freqMap;
    set<Node> nodes;
    void updateFreq(ll value, int delta) {
        if (freqMap.contains(value)) {
            int oldFreq = freqMap[value];
            int newFreq = oldFreq + delta;
            auto it = nodes.find({value, oldFreq});
            nodes.erase(it);
            if (newFreq == 0) {
                freqMap.erase(value);
            }
            else {
                freqMap[value] = newFreq;
                nodes.insert({value, newFreq});
            }
        }
        else {
            Node node(value, 1);
            freqMap[node.value] = node.freq;
            nodes.insert(node);
        }
    }
    ll getMode() const {
        if (nodes.empty()) {
            throw std::invalid_argument("Mode not found!");
        }
        return nodes.begin()->value;
    }
};

struct RBTreeNode {
    ll value;
    int id;
    RBTreeNode(ll value, int id) : value(value), id(id) {};
    RBTreeNode() = default;
    bool operator < (const RBTreeNode& other) const {
        if (value == other.value) {
            return id < other.id;
        }
        return value < other.value;
    }
};

class StatisticsTracker {
private:
    ll sum;
    ll n;
    int id;
    ModeTracker modeTracker;
    queue<ll> q;
    __gnu_pbds::tree<RBTreeNode, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> rbtree;
public:
    StatisticsTracker() : sum(0), n(0), id(0) {}
    
    void addNumber(int number) {
        sum += static_cast<ll>(number);
        ++n;
        q.push(number);
        rbtree.insert({number, id});
        ++id;
        modeTracker.updateFreq(number, 1);
    }
    
    void removeFirstAddedNumber() {
        ll value = q.front();
        q.pop();
        --n;
        sum -= value;
        modeTracker.updateFreq(value, -1);
        rbtree.erase(rbtree.upper_bound(RBTreeNode(value, MIN_ID)));
    }
    
    int getMean() {
        return static_cast<int>(sum / n);
    }
    
    int getMedian() {
        return (n & 1) ? rbtree.find_by_order((n - 1) >> 1)->value : rbtree.find_by_order(n >> 1)->value;
    }
    
    int getMode() {
        return modeTracker.getMode();
    }
};

/**
 * Your StatisticsTracker object will be instantiated and called as such:
 * StatisticsTracker* obj = new StatisticsTracker();
 * obj->addNumber(number);
 * obj->removeFirstAddedNumber();
 * int param_3 = obj->getMean();
 * int param_4 = obj->getMedian();
 * int param_5 = obj->getMode();
 */