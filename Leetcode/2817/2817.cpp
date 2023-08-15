class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == 0) {
            return 0;
        }
        multiset<int> left, right;
        int n = (int)nums.size();
        for (int i = x; i < n; ++i) {
            right.insert(nums.at(i));
        }
        int minDiff = numeric_limits<int>::max();
        multiset<int>::iterator iter;
        for (int i = 0; i < n; ++i) {

            if (!left.empty()) {
                if (nums[i] <= (*left.begin())) {
                    minDiff = min(minDiff, abs(nums.at(i) - (*left.begin())));
                }
                else {
                    iter = left.lower_bound(nums.at(i));
                    if (iter != left.end()) {
                        minDiff = min(minDiff, abs(nums.at(i)-(*iter)));
                    }
                    --iter;
                    minDiff = min(minDiff, abs(nums.at(i)-(*iter)));
                }
            }
            if (!right.empty()) {
                if (nums.at(i) <= (*right.begin())) {
                    minDiff = min(minDiff, abs(nums.at(i) - (*right.begin())));
                }
                else {
                    iter = right.lower_bound(nums.at(i));
                    if (iter != right.end()) {
                        minDiff = min(minDiff, abs(nums.at(i)-(*iter)));
                    }
                    --iter;
                    minDiff = min(minDiff, abs(nums.at(i)-(*iter)));
                }
            }
            if (i+1-x >= 0) {
                left.insert(nums.at(i+1-x));
            }
            if (!right.empty()) {
                right.erase(right.find(nums.at(i+x)));
            }
        }
        return minDiff;
    }
};