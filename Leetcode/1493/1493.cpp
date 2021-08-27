class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<pair<int,int> > v;
        int counter = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (last == -1) {
                last = nums[i];
                ++counter;
                continue;
            }
            if (last == 0) {
                if (nums[i] == 0) {
                    ++counter;
                } else {
                    v.emplace_back(last, counter);
                    counter = 1;
                    last = nums[i];
                }
            }
            else {
                if (nums[i] == 1) {
                    ++counter;
                } else {
                    v.emplace_back(last, counter);
                    counter = 1;
                    last = nums[i];
                }
            }
        }
        if (counter > 0) {
            v.emplace_back(last, counter);
        }
        // corner case
        if (v.size() == 1) {
            if (v[0].first == 1) {
                return v[0].second-1;
            } else {
                return 0;
            }
        }
        int ans = 0;
        int length = (int)v.size();
        for (int i = 0; i < length; ++i) {
            if (v[i].first == 1) {
                ans = max(ans, v[i].second);
            }
        }
        int temp1, temp2;
        for (int i = 0; i < length; ++i) {
            if (v[i].first == 0 && v[i].second == 1) {
                if (i-1 >= 0 && i-1 < length) {
                    temp1 = v[i-1].second;
                } else {
                    temp1 = 0;
                }
                if (i+1 >= 0 && i+1 < length) {
                    temp2 = v[i+1].second;
                } else {
                    temp2 = 0;
                }
                ans = max(ans, temp1+temp2);
            }
        }
        return ans;
    }
};