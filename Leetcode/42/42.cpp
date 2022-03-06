class Solution {
public:
    // O(nlogn)
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n <= 2) return 0;
        vector<int> maxFromLeft;
        multiset<int, greater<int>> right;
        maxFromLeft.emplace_back(height[0]);
        for (int i = 2; i < n; ++i) {
            right.insert(height[i]);
        }
        int sum = 0;
        for (int i = 1; i < n-1; ++i) {
            sum += max(min(maxFromLeft.back(), *right.begin()) - height[i], 0);
            maxFromLeft.emplace_back(max(maxFromLeft.back(), height[i]));
            right.erase(right.lower_bound(height[i+1]));
        }
        return sum;
    }
};