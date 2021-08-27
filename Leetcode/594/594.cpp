class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> stats;
        for (const auto &i : nums) {
            ++stats[i];
        }
        int counter = 0;
        for (const auto &[k,v] : stats) {
            if (stats.find(k-1) != stats.end()) {
                counter = max(counter, stats[k-1]+v);
            }
            if (stats.find(k+1) != stats.end()) {
                counter = max(counter, stats[k+1]+v);
            }
        }
        return counter;
    }
};