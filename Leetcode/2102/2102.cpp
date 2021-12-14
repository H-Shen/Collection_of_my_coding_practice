#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

struct Node {
    string name;
    int score;
    Node(string name, int score) : name(name), score(score) {}
    Node() = default;
    bool operator > (const Node &node) const {
        if (score == node.score) {
            return name < node.name;
        }
        return score > node.score;
    }
};

using namespace __gnu_pbds;
using RBTree = tree<Node, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update>; 

class SORTracker {
private:
    RBTree t;
    int i;
public:
    SORTracker() : i(0) {
        
    }
    
    void add(string name, int score) {
        t.insert(Node(name, score));
    }
    
    string get() {
        string ans = t.find_by_order(i)->name;
        ++i;
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */