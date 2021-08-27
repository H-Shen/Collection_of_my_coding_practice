class Solution {
public:
    void sortColors(vector<int> &nums) {
        unordered_map<int, int> A;
        A[0] = 0, A[1] = 0, A[2] = 0;
        for (const auto &i : nums) ++A[i];
        size_t i = 0;
        while (A[0] != 0) {
            nums[i++] = 0;
            --A[0];
        }
        while (A[1] != 0) {
            nums[i++] = 1;
            --A[1];
        }
        while (A[2] != 0) {
            nums[i++] = 2;
            --A[2];
        }
    }
};