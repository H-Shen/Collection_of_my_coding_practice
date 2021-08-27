class Solution {
public:
    bool checkIfPangram(string sentence) {
        constexpr int MAXN = 26;
        bitset<MAXN> vis;
        for (const auto &i : sentence) vis[i - 'a'] = true;
        return vis.all();
    }
};