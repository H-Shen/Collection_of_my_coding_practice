using ll = long long;

constexpr ll MOD = 1e9+7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        ll maxHeight = horizontalCuts[0];
        int n = (int)horizontalCuts.size();
        for (int i = 1; i < n; ++i) {
            maxHeight = max(maxHeight, (ll)(horizontalCuts[i] - horizontalCuts[i-1]));
        }
        maxHeight = max(maxHeight, (ll)h - horizontalCuts.back());
        
        sort(verticalCuts.begin(),verticalCuts.end());
        ll maxWidth = verticalCuts[0];
        int m = (int)verticalCuts.size();
        for (int i = 1; i < m; ++i) {
            maxWidth = max(maxWidth, (ll)(verticalCuts[i] - verticalCuts[i-1]));
        }
        maxWidth = max(maxWidth, (ll)w - verticalCuts.back());
        
        return maxHeight * maxWidth % MOD;
    }
};