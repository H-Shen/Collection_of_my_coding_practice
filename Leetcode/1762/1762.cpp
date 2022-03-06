class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = (int)heights.size();
        vector<int> ans;
        int maxFromRight = heights.back();
        ans.emplace_back(n-1);
        for (int i = n-2; i >= 0; --i) {
            if (heights[i] > maxFromRight) {
                ans.emplace_back(i);
                maxFromRight = heights[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};