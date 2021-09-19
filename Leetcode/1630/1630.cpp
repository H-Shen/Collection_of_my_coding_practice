constexpr int MAXN = 505;
int A[MAXN];
int B[MAXN];

class Solution {
public:
    bool check(int l, int r) {
        if (r-l<=1) return true;
        int n = r-l+1;
        memcpy(B, &A[l], n*sizeof(int));
        sort(B, B+n);
        int diff = B[1]-B[0];
        for (int i = 1; i < n; ++i) {
            if (B[i]-B[i-1] != diff) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        for (size_t i = 0; i != nums.size(); ++i) {
            A[i] = nums[i];
        }
        int n = (int)l.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = check(l[i], r[i]);
        }
        return ans;
    }
};