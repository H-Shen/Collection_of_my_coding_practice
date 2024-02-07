class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = (int)nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                vector<int> vec;
                for (int k = 0; k < n; ) {
                    if (k >= i && k <= j) {
                        ++k;
                    }
                    else {
                        vec.emplace_back(nums[k]);
                        ++k;
                    }
                }
                int length = (int)vec.size();
                bool hasAns = true;
                if (length > 1) {
                    for (int k = 1; k < length; ++k) {
                        if (vec[k-1] >= vec[k]) {
                            hasAns = false;
                            break;
                        }
                    }
                    if (hasAns) {
                        ++cnt;
                    }
                }
                else {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};