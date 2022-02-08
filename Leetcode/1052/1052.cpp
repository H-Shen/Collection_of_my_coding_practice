class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = (int)customers.size();
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                vec[i] = 0;
            }
            else {
                vec[i] = customers[i];
            }
        }
        int maxVal = 0;
        int currentVal = 0;
        // Sliding window
        for (int i = 0; i < minutes; ++i) {
            currentVal += vec[i];
        }
        maxVal = max(maxVal, currentVal);
        int left = 0, right = minutes-1;
        for (int i = minutes, j = 0; i < n; ++i, ++j) {
            currentVal = currentVal + vec[i] - vec[j];
            if (currentVal > maxVal) {
                maxVal = currentVal;
                left = j+1;
                right = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= left && i <= right) {
                ans += customers[i];
            }
            else {
                if (grumpy[i] == 0) {
                    ans += customers[i];
                }
            }
        }
        return ans;
    }
};