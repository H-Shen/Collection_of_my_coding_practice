class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int stats[2]{};
        int n = (int)bills.size();
        for (int i = 0; i < n; ++i) {
            if (bills[i] == 5) {
                ++stats[0];
            }
            else if (bills[i] == 10) {
                if (stats[0] == 0) {
                    return false;
                }
                --stats[0];
                ++stats[1];
            }
            else {
                // 10+5
                if (stats[1] > 0 && stats[0] > 0) {
                    --stats[1];
                    --stats[0];
                }
                // 5+5+5
                else if (stats[0] >= 3) {
                    stats[0] -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};