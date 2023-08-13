class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        constexpr int MAXN = 55;
        bitset<MAXN> vis;
        int step;
        int currentPos = 0;
        int i = 1;
        int totalSteps;
        while (true) {
            step = i * k;
            if (vis[currentPos]) {
                break;
            }
            vis[currentPos] = true;
            while (step > 0) {
                ++currentPos;
                if (currentPos >= n) {
                    currentPos = 0;
                }
                --step;
            }
            ++i;
        }
        vector<int> ans;
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                ans.emplace_back(j+1);
            }
        }
        return ans;
    }
};