class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        unordered_map<int, int> A;
        for (const auto &i : nums) {
            ++A[i];
        }
        int len = static_cast<int>(nums.size() / 3);
        int newLen = 0;
        for (const auto it : A) {
            if (it.second > len) {
                nums[newLen++] = it.first;
            }
        }
        nums.resize(newLen);
        return nums;
    }
};