class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        // coordinate compression
        int n = (int)lights.size();
        vector<int> vec(2*n);
        int pos, range;
        for (int i = 0, j = 0; i < n; ++i, j += 2) {
            pos = lights[i][0];
            range = lights[i][1];
            vec[j] = pos-range;
            vec[j+1] = pos+range;
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()), vec.end());
        // difference array
        int length = (int)vec.size();
        vector<int> pre(length+1);
        int l,r;
        for (int i = 0; i < n; ++i) {
            pos = lights[i][0];
            range = lights[i][1];
            l = (int)(lower_bound(vec.begin(),vec.end(),pos-range) - vec.begin());
            r = (int)(lower_bound(vec.begin(),vec.end(),pos+range) - vec.begin());
            ++pre[l];
            --pre[r+1];
        }
        for (int i = 1; i <= length; ++i) {
            pre[i] += pre[i-1];
        }
        int maxVal = 0;
        for (int i = 0; i < length; ++i) {
            maxVal = max(maxVal, pre[i]);
        }
        for (int i = 0; i < length; ++i) {
            if (pre[i] == maxVal) {
                return vec[i];
            }
        } 
        return -1;
    }
};