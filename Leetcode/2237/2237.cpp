class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> diff(n+1);
        int l, r;
        for (auto&i : lights) {
            l = max(0, i[0] - i[1]);
            r = min(n-1, i[0] + i[1]);
            ++diff[l];
            --diff[r+1];
        }
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i-1];
        }
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (diff[i] >= requirement[i]) {
                ++counter;
            }
        }
        return counter;
    }
};