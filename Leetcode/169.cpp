class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> A;
        for (const auto &i : nums) {
            ++A[i];
        }
        int len = static_cast<int>(nums.size());
        int res = nums.at(0);
        for (const auto it : A) {
            if (it.second > len / 2) {
                res = it.first;
                break;
            }
        }
        return res;
    }
};