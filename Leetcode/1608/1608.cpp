class Solution {
public:
    int specialArray(vector<int>& nums) {
        constexpr int MINN = 0;
        sort(nums.begin(), nums.end());
        int answer = -1;
        for (int i = MINN; i <= nums.back() + 5; ++i) {
            if ((int)(nums.size() - (lower_bound(nums.begin(), nums.end(), i) - nums.begin())) == i) {
                answer = i;
                break;
            } 
        }
        return answer;
    }
};