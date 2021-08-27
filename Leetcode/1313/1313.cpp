class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        int n = (int)nums.size();
        n = (n - 2) / 2;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < nums.at(2 * i); ++j) {
                result.emplace_back(nums.at(2 * i + 1));
            }
        }
        return result;
    }
};