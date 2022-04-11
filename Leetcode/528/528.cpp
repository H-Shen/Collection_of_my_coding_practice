class Solution {
private:
    struct Node {
        int index,l,r;
        Node() = default;
        Node(int index, int l, int r) : index(index), l(l), r(r) {}
        bool operator < (const Node& node) const {
            return l < node.l;
        }
    };
    vector<Node> nodes;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> dist;
public:
    Solution(vector<int>& w) {
        int n = (int)w.size();
        int l, r;
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                l = 1;
                r = w[0];
            }
            else {
                l = r+1;
                r = l+w[i]-1;
            }
            nodes.emplace_back(Node(i, l, r));
            tot += w[i];
        }
        dist = uniform_int_distribution<int>{1, tot};
    }
    int pickIndex() {
        int pos = dist(rng);
        Node node(-1,pos,-1);
        auto iter = lower_bound(nodes.begin(),nodes.end(),node);
        if (binary_search(nodes.begin(),nodes.end(),node)) {
            return iter->index;
        }
        --iter;
        return iter->index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */