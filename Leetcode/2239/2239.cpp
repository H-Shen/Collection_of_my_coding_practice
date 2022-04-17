class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end(), [](const auto &l, const auto &r){
            int a = abs(l);
            int b = abs(r);
            if (a == b) {
                return l > r;
            }
            return a < b;
        });
    }
};