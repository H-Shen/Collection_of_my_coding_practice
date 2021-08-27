class Solution {
public:
    bool check(const vector<int> &A) {
        int n = (int)A.size();
        for (int i = 1; i < n; ++i) {
            if (A[i-1] >= A[i]) return false;
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1) return true;
        for (int i = 0; i < n; ++i) {
            vector<int> numsCopy(nums);
            numsCopy.erase(numsCopy.begin()+i);
            if (check(numsCopy)) return true;
        }
        return false;
    }
};