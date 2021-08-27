class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {

        bool canReshape = true;
        if (nums.empty()) {
            canReshape = false;
        }
        int len = static_cast<int>(nums.size() * nums[0].size());
        if (len != r * c) {
            canReshape = false;
        }

        if (canReshape) {
            vector<vector<int> > res(static_cast<unsigned long>(r));
            for (auto &&p : res) {
                p.resize(static_cast<unsigned long>(c));
            }
            size_t m = 0, n = 0;
            for (const auto &i : nums) {
                for (const auto &j : i) {
                    res[m][n++] = j;
                    if (n == c) {
                        n = 0;
                        ++m;
                    }
                }
            }
            return res;
        }
        return nums;
    }
};