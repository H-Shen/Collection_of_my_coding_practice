class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (auto iter = lower_bound(nums.begin(),nums.end(),0); iter == nums.end()) {
            transform(nums.begin(),nums.end(),nums.begin(),[](int x){return x*x;});
            reverse(nums.begin(),nums.end());
        } else {
            transform(nums.begin(),nums.end(),nums.begin(),[](int x){return x*x;});
            reverse(nums.begin(),iter);
            inplace_merge(nums.begin(),iter,nums.end());
        }
        return nums;
    }
};

//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        vector<int> v1, v2;
//        vector<int> ans(nums.size());
//        int pos = 0;
//        for (auto& i : nums) {
//            if (i < 0) v1.emplace_back(i*i);
//            else if (i == 0) ans[pos++] = 0;
//            else v2.emplace_back(i*i);
//        }
//        int n = (int)v1.size();
//        int m = (int)v2.size();
//        int i = n-1, j = 0;
//        while (i >= 0 && j < m) {
//            if (v1[i] < v2[j]) {
//                ans[pos++] = v1[i--];
//            }
//            else {
//                ans[pos++] = v2[j++];
//            }
//        }
//        while (i >= 0) ans[pos++] = v1[i--];
//        while (j < m) ans[pos++] = v2[j++];
//        return ans;
//    }
//};