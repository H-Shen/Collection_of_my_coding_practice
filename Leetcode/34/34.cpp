class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (binary_search(nums.begin(), nums.end(), target)) {
            auto f = equal_range(nums.begin(), nums.end(), target);
            return vector<int>
                    {
                            static_cast<int>(distance(nums.begin(), f.first)),
                            static_cast<int>(distance(nums.begin(), f.second - 1))
                    };
        }
        return vector<int>{-1, -1};
    }
};