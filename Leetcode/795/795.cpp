using ll = long long;

class Solution {
public:
    int solve(vector<int>& nums, int l, int r, int left, int right) {
        ll n = r-l+1;
        ll counter = (n*(n+1))>>1;
        ll counter2 = -1;
        for (int i = l; i <= r; ++i) {
            if (nums[i] < left) {
                if (counter2 == -1) {
                    counter2 = 1;
                }
                else {
                    ++counter2;
                }
            }
            else {
                if (counter2 > 0) {
                    counter -= (counter2*(counter2+1))>>1;
                    counter2 = -1;
                }
            }
        }
        if (counter2 > 0) {
            counter -= (counter2*(counter2+1))>>1;
        }
        return (int)counter;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = (int)nums.size();
        int counter = 0;
        int l = -1;
        int r = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) {
                if (r != -1) {
                    counter += solve(nums, l, r, left, right);
                    l = -1;
                    r = -1;
                }
            }
            else {
                if (r != -1) {
                    r = i;
                }
                else {
                    l = i;
                    r = i;
                }
            }
        }
        if (l != -1) {
            counter += solve(nums, l, r, left, right);
        }
        return counter;
    }
};