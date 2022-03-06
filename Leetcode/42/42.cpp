class Solution {
public:
    // O(nlogn)
    // trap[i] = max(min(maxFromLeft[i-1], maxFromRight[i+1]) - height[i], 0)
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n <= 2) return 0;
        multiset<int, greater<int>> left, right;
        left.insert(height[0]);
        for (int i = 2; i < n; ++i) {
            right.insert(height[i]);
        }
        multiset<int, greater<int>>::iterator iter1, iter2;
        int sum = 0;
        for (int i = 1; i < n-1; ++i) {
            sum += max(min(*left.begin(), *right.begin()) - height[i], 0);
            left.insert(height[i]);
            right.erase(right.lower_bound(height[i+1]));
        }
        return sum;
    }
};