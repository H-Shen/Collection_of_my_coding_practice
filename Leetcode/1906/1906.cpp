constexpr int MINVAL = 1;
constexpr int MAXVAL = 100;

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        vector<int> indices[MAXVAL+5]{};
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].emplace_back(i);
        }
        int l, r;
        int m = (int)queries.size();
        vector<int> answer(m);
        for (int i = 0; i < m; ++i) {
            l = queries[i][0];
            r = queries[i][1];
            int minAbs = -1;
            int a = -1;
            int b = -1;
            for (int j = MINVAL; j <= MAXVAL; ++j) {
                auto iter = lower_bound(indices[j].begin(),indices[j].end(),l);
                if (iter != indices[j].end() && *iter <= r) {
                    if (a == -1) {
                        a = j;
                    }
                    else {
                        b = j;
                        if (minAbs == -1) {
                            minAbs = b - a;
                        }
                        else {
                            minAbs = min(minAbs, b - a);
                        }
                        a = b;
                    }
                }
            }
            answer[i] = minAbs;
        }
        return answer;
    }
};