constexpr int MAXN = 18;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = (int)nums.size();
        int total = 1<<n;
        int maxVal = -1;
        int temp;
        for (int i = 1; i < total; ++i) {
            bitset<MAXN> bs(i);
            temp = -1;
            for (int j = 0; j < n; ++j) {
                if (bs[j]) {
                    if (temp == -1) {
                        temp = nums[j];
                    } else {
                        temp |= nums[j];
                    }
                }
            }
            maxVal = max(maxVal, temp);
        }
        int counter = 0;
        for (int i = 1; i < total; ++i) {
            bitset<MAXN> bs(i);
            temp = -1;
            for (int j = 0; j < n; ++j) {
                if (bs[j]) {
                    if (temp == -1) {
                        temp = nums[j];
                    } else {
                        temp |= nums[j];
                    }
                }
            }
            if (temp == maxVal) {
                ++counter;
            }
        }
        return counter;
    }
};