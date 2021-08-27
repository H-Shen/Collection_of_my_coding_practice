class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int height = (int)wall.size();
        int rowSum = accumulate(wall[0].begin(), wall[0].end(), 0);
        unordered_map<int, int> stats;
        for (const auto &i : wall) {
            if (i.size() > 1) {
                ++stats[i.front()];
                int cur = i.front();
                for (size_t j = 1; j != i.size(); ++j) {
                    cur += i[j];
                    if (cur != rowSum) {
                       ++stats[cur];   
                    }
                }
            }
        }
        int maxGap = 0;
        for (const auto &[k, v] : stats) {
            maxGap = max(maxGap, v);
        }
        return height - maxGap;
    }
};