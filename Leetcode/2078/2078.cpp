class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = (int)colors.size();
        int ans = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    ans = max(ans, abs(i-j));
                }
            }
        }
        return ans;
    }
};