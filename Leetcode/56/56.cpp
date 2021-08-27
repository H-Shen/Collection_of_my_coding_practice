class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 差分数组 同时记录最小最大值
        constexpr int MAXN = 1e4+5;
        vector<int> diff(MAXN);
        int minVal = numeric_limits<int>::max();
        int maxVal = numeric_limits<int>::min();
        vector<int> singlePoints;   // 单独处理点
        int l, r;
        for (const auto &i : intervals) {
            if (i[0] == i[1]) {
                singlePoints.emplace_back(i[0]);
                continue;
            }
            l = i[0];
            r = i[1];
            minVal = min(minVal, l);
            maxVal = max(maxVal, r);
            ++diff[l];
            --diff[r];
        }
        // 还原
        vector<int> original(MAXN);
        for (int i = 0; i < MAXN; ++i) {
            if (i == 0) {
                original[i] = diff[i];
            } else {
                original[i] = original[i-1] + diff[i];
            }
        }
        vector<vector<int> > ans;
        int startIndex = -1, endIndex = -1;
        for (int i = 0; i < MAXN; ++i) {
            if (original[i] > 0) {
                if (endIndex == -1) {
                    startIndex = i;
                    endIndex = i;
                }
                else {
                    ++endIndex;
                }
            }
            else {
                if (endIndex != -1) {
                    ans.emplace_back(vector<int>{startIndex, endIndex+1});
                    startIndex = -1;
                    endIndex = -1;
                }
            }
        }
        if (endIndex != -1) {
            ans.emplace_back(vector<int>{startIndex, endIndex+1});
        }
        bitset<MAXN> temp;
        for (const auto &j : ans) {
            for (int i = j[0]; i <= j[1]; ++i) {
                temp[i] = true;
            }
        }
        for (const auto &i : singlePoints) {
            if (!temp[i]) {
                ans.emplace_back(vector<int>{i,i});
            }
        }
        // 去重
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        
        return ans;
    }
};