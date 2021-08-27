class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) return n-1;
        restrictions.emplace_back(vector<int>{1, 0});
        sort(restrictions.begin(), restrictions.end(), [](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        if (restrictions.back().front() != n) {
            restrictions.emplace_back(vector<int>{n, n-1});
        }
        int m = (int)restrictions.size();
        int temp;
        for (int i = 1; i < m; ++i) {
            temp = restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]);
            if (temp < restrictions[i][1]) {
                restrictions[i][1] = temp;
            }
        }
        for (int i = m-2; i >= 0; --i) {
            temp = restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]);
            if (temp < restrictions[i][1]) {
                restrictions[i][1] = temp;
            }
        }
        int maxValue = 0;
        int idDiff;
        for (int i = 0; i < m-1; ++i) {
            idDiff = restrictions[i+1][0] - restrictions[i][0];
            temp = (idDiff+restrictions[i][1]+restrictions[i+1][1]) >> 1;
            maxValue = max(maxValue, temp);
        }
        return maxValue;
    }
};