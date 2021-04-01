class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        constexpr int MAXN = 10005;
        bitset<MAXN> vis;
        for (const auto &i : A) {
            if (vis[i]) return i;
            vis[i] = true;
        }
        return -1;
    }
};