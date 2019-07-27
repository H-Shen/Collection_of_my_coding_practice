class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector <int> res;
        int dup = 0, lost = 0;
        unordered_map <int, int> A;
        for (const auto &p : nums) {
            ++A[p];
        }
        for (int i = 1; i <= static_cast<int>(nums.size()); ++i) {
            if (A.find(i) == A.end()) {
                lost = i;
            }
            else if (A[i] != 1) {
                dup = i;
            }
        }
        res.push_back(dup);
        res.push_back(lost);
        return res;
    }
};