class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        int l = 0, r = n-1;
        int maxVal = -1;
        while (l < r) {
            maxVal = max(maxVal, min(height[l],height[r]) * (r-l));
            if (height[l] < height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return maxVal;
    }
};