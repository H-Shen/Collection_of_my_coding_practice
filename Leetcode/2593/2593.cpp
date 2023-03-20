using ll = long long;

struct Node {
    ll val;
    int index;
    Node() = default;
    Node(ll val, int index) : val(val), index(index) {}
    bool operator < (const Node& other) const {
        if (val == other.val) {
            return index < other.index;
        }
        return val < other.val;
    }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = (int)nums.size();
        set<Node> s;
        for (int i = 0; i < n; ++i) {
            s.emplace(nums[i], i);
        }
        ll sum = 0;
        vector<bool> vis(n, false);
        Node node;
        int newIndex;
        while (!s.empty()) {
            node = *s.begin();
            sum += node.val;
            vis[node.index] = true;
            // left
            newIndex = node.index-1;
            if (newIndex >= 0 && newIndex < n && !vis[newIndex]) {
                vis[newIndex] = true;
                s.erase(s.find(Node(nums[newIndex], newIndex)));
            }
            // right
            newIndex = node.index+1;
            if (newIndex >= 0 && newIndex < n && !vis[newIndex]) {
                vis[newIndex] = true;
                s.erase(s.find(Node(nums[newIndex], newIndex)));
            }
            s.erase(s.find(node));
        }
        return sum;
    }
};