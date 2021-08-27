class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        ll sum = 0;
        int n = (int)nums1.size();
        for (int i = 0; i < n; ++i) {
            sum += abs(nums1[i] - nums2[i]);
        }
        vector<int> v(nums1);
        ll result = sum;
        ll new_sum = sum;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            if (nums1[i] != nums2[i]) {
                if (binary_search(v.begin(), v.end(), nums2[i])) {
                    new_sum = sum - abs(nums1[i] - nums2[i]) + 0;
                    result = min(result, new_sum);
                }
                else if (nums2[i] < v.front()) {
                    new_sum = sum - abs(nums1[i] - nums2[i]) + abs(v.front() - nums2[i]);
                    result = min(result, new_sum);
                }
                else if (nums2[i] > v.back()) {
                    new_sum = sum - abs(nums1[i] - nums2[i]) + abs(nums2[i] - v.back());
                    result = min(result, new_sum);
                }
                else {
                    auto iter = lower_bound(v.begin(), v.end(), nums2[i]);
                    int temp = *iter;
                    new_sum = sum - abs(nums1[i] - nums2[i]) + abs(nums2[i] - temp);
                    result = min(result, new_sum);
                    --iter;
                    temp = *iter;
                    new_sum = sum - abs(nums1[i] - nums2[i]) + abs(nums2[i] - temp);
                    result = min(result, new_sum);
                }
            }
        }
        return (int)(result % 1000000007LL);
    }
};