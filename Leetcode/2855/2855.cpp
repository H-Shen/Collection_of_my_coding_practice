class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = (int)nums.size();
        int cnt = 0;
        if (is_sorted(nums.begin(),nums.end())) {
            return cnt;
        }
        for (int i = 0; i < n-1; ++i) {
            rotate(nums.rbegin(),nums.rbegin()+1,nums.rend());
            ++cnt;
            if (is_sorted(nums.begin(),nums.end())) {
                return cnt;
            }
        }
        return -1;
    }
};