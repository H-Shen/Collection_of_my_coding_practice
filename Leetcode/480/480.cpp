#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

struct Node {
    int val, id;
    explicit Node(int val, int id) : val(val), id(id) {}
    Node() = default;
    bool operator < (const Node &o) const {
        if (val == o.val) return id < o.id;
        return val < o.val;
    }
};

using RBTree = tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        if (nums.empty()) return result;
        RBTree t;
        int n = (int)nums.size();
        for (int i = 0; i < k; ++i) {
            t.insert(Node(nums.at(i), i));
        }
        double sum, l, r;
        if (!(k & 1)) {
            for (int i = 0, j = k - 1; j < n;) {
                l = t.find_by_order(k >> 1)->val;
                r = t.find_by_order((k >> 1) - 1)->val;
                sum = l + (r - l) / 2.0;
                result.emplace_back(sum);
                if (j == n - 1) break;
                t.erase(Node(nums.at(i), i));
                ++i;
                ++j;
                t.insert(Node(nums.at(j), j));
            }
        }
        else {
            for (int i = 0, j = k - 1; j < n;) {
                sum = t.find_by_order((k - 1) >> 1)->val;
                result.emplace_back(sum);
                if (j == n - 1) break;
                t.erase(Node(nums.at(i), i));
                ++i;
                ++j;
                t.insert(Node(nums.at(j), j));
            }
        }
        return result;
    }
};