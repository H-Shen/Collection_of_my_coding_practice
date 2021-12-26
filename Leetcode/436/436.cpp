struct Node {
    int index;
    int start;
    Node(int index, int start) : index(index), start(start){}
    Node() = default;
    bool operator < (const Node &node) const {
        return start < node.start;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        set<Node> s;
        for (int i = 0; i < n; ++i) {
            s.insert(Node(i, intervals[i][0]));
        }
        vector<int> ans(n);
        Node node;
        for (int i = 0; i < n; ++i) {
            node.start = intervals[i][1];
            auto iter = s.lower_bound(node);
            if (iter == s.end()) {
                ans[i] = -1;
            }
            else {
                ans[i] = iter->index;
            }
        }
        return ans;
    }
};