class Solution {
public:
    // O(n)
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n <= 2) return 0;
        vector<int> maxFromRight(n);
        maxFromRight[n-1] = height[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxFromRight[i] = max(maxFromRight[i+1], height[i]);
        }
        int maxFromLeft = height[0];
        int sum = 0;
        for (int i = 1; i < n-1; ++i) {
            sum += max(min(maxFromLeft, maxFromRight[i+1]) - height[i], 0);
            maxFromLeft = max(maxFromLeft, height[i]);
        }
        return sum;
    }
};