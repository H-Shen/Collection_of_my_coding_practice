constexpr int MAXN = 1e5+5;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // 离散化
        int n = (int)events.size();
        vector<int> vec(n*2);
        for (int i = 0, j = 0; i < n; ++i) {
            vec[j] = events[i][0]-1;
            vec[j+1] = events[i][1];
            j += 2;
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        int maxFromRight[MAXN]{};
        for (int i = 0; i < n; ++i) {
            events[i][0] = (int)(lower_bound(vec.begin(),vec.end(),events[i][0]-1) - vec.begin());
            maxFromRight[events[i][0]] = max(maxFromRight[events[i][0]], events[i][2]);
            events[i][1] = (int)(lower_bound(vec.begin(),vec.end(),events[i][1]) - vec.begin());
        }
        for (int i = MAXN-2; i >= 0; --i) {
            maxFromRight[i] = max(maxFromRight[i+1], maxFromRight[i]);
        }
        int maxVal = 0;
        // Choose 1:
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, events[i][2]);
        }
        // Choose 2:
        for (int i = 0; i < n; ++i) {
            maxVal = max(maxVal, events[i][2] + maxFromRight[events[i][1]]);
        }
        return maxVal;
    }
};