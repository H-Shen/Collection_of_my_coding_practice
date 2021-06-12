using ll = long long;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = accumulate(chalk.begin(), chalk.end(), (ll)0);
        int n = (int)chalk.size();
        if (sum <= k) {
            k %= sum;
        }
        ll cursum = 0;
        for (int i = 0; i < n; ++i) {
            if (cursum + chalk[i] > (ll)k) {
                return i;
            }
            cursum += chalk[i];
        }
        return -1;
    }
};