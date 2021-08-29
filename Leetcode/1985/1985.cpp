class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),  nums.end(), [](const string &l, const string &r) {
            if (l.size() == r.size()) {
                for (size_t i = 0; i != l.size(); ++i) {
                    if (l[i] != r[i]) {
                        return l[i] > r[i];
                    }
                }
            }
            return l.size() > r.size();
        });
        return nums[k-1];
    }
};