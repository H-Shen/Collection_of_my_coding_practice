class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt = 0;
        int dist = 0;
        for (const auto &i : nums) {
            dist += i;
            if (dist == 0) ++cnt;
        }
        return cnt;
    }
};