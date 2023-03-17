using ll = long long;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int n = (int)nums.size();
        vector<ll> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + (ll)nums[i];
        }
        return (int)count_if(pre.begin(),pre.end(),[&](const ll&x){return x > 0;});
    }
};