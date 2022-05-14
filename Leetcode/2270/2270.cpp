using ll = long long;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<ll> preFromRight(n);
        preFromRight[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            preFromRight[i] = preFromRight[i+1] + nums[i];
        }
        int counter = 0;
        ll sumLeft = 0;
        for (int i = 0; i < n-1; ++i) {
            sumLeft += nums[i];
            if (sumLeft >= preFromRight[i+1]) ++counter;
        }
        return counter;
    }
};