class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        constexpr int MAXN = 1005;
        int in[MAXN]{};
        int out[MAXN]{};
        for (const auto &i : trips) {
            in[i[1]] += i[0];
            out[i[2]] += i[0];
        }
        int sum = 0;
        for (int i = 0; i < MAXN; ++i) {
            sum = sum - out[i] + in[i];
            if (sum < 0 || sum > capacity) {
                return false;
            }
        }
        return true;
    }
};