template<int N, int L>
struct Trie {
    Trie* next[N]{nullptr};
    void insert(int x) {
        Trie* node = this;
        for (int i = L; i >= 0; --i) {
            int u = x >> i & 1;
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
    int findMaximumXOR(vector<int>& nums) {
        auto t = new Trie<2, 30>();
        for (const auto &i : nums) t->insert(i);
        int ans = -1;
        for (const auto &i : nums) {
            ans = max(ans, t->query(i));
        }
        return ans;
    }
};