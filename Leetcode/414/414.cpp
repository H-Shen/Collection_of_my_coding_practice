class Solution {
public:
    int thirdMax(vector<int> &nums) {
        unordered_set<int> A(nums.begin(), nums.end());
        int maxOne = *max_element(nums.begin(), nums.end());
        if (A.size() < 3) {
            return maxOne;
        }
        auto subMax = [](const unordered_set<int> &A, const int maxVal) -> int {
            int res = maxVal;
            for (auto it = A.cbegin(); it != A.cend(); ++it) {
                if (*it < maxVal) {
                    res = *it;
                    break;
                }
            }
            for (auto it = A.cbegin(); it != A.cend(); ++it) {
                if (*it < maxVal) {
                    res = max(res, *it);
                }
            }
            return res;
        };
        return subMax(A, subMax(A, maxOne));
    }
};