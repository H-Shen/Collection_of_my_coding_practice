class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // greedy: min(result) = (b_1+b_2+...+b_n) + min((a_1-b_1) + (a_2-b_2) + ... + (a_{n/2}-b_{n/2}))
        auto cmp = [](const auto &l, const auto &r) { return l[0]-l[1] < r[0]-r[1]; };
        int result = 0;
        for (const auto &i : costs) result += i[1];
        sort(costs.begin(), costs.end(), cmp);
        int n = (int)costs.size();
        for (int i = 0; i < n / 2; ++i) {
            result += costs[i][0] - costs[i][1];
        }
        return result;
    }
};