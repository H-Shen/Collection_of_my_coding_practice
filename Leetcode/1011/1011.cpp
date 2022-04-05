class Solution {
public:
    bool check(vector<int>&weights, int n, int mid, int days) {
        int countDays = 0;
        int currentWeight = 0;
        for (int i = 0; i < n;) {
            if (currentWeight + weights[i] > mid) {
                ++countDays;
                if (countDays > days) {
                    return false;
                }
                currentWeight = 0;
            }
            else {
                currentWeight += weights[i];
                ++i;
            }
        }
        if (currentWeight > 0) {
            ++countDays;
            if (countDays > days) {
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = (int)weights.size();
        int l = 1;
        int r = 0;
        for (auto&i : weights) r += i;
        int mid;
        int ans = numeric_limits<int>::max();
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(weights, n, mid, days)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};