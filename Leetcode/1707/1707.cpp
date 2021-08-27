template<int N, int L>
struct Trie {
    Trie* next[N] = {nullptr};
    void insert(int x) {
        Trie* node = this;
        for (int i = L; i >= 0; --i) {
            int u = (x >> i) & 1;
            if (!node->next[u]) {
                node->next[u] = new Trie();
            }
            node = node->next[u];
        }
    }
    int query(int x) {
        Trie* node = this;
        int res = 0;
        for (int i = L; i >= 0; --i) {
            if (!node) {
                return -1;
            }
            int u = x >> i & 1;
            if (node->next[!u]) {
                node = node->next[!u];
                res = (res << 1) + (!u);
            } else {
                node = node->next[u];
                res = (res << 1) + u;
            }
        }
        res ^= x;
        return res;
    }
};
class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int m = (int)queries.size();
        for (int i = 0; i < m; ++i) {
            queries[i].emplace_back(i);
        }
        sort(queries.begin(), queries.end(), [](const auto &l, const auto &r){
            return l[1] < r[1];
        });
        auto t = new Trie<2, 30>();
        int n = (int)nums.size();
        int index = 0;
        vector<int> result(queries.size());
        for (const auto &i : queries) {
            while (index < n && nums[index] <= i[1]) {
                t->insert(nums[index]);
                ++index;
            }
            result[i[2]] = t->query(i[0]);
        }
        return result;
    }
};