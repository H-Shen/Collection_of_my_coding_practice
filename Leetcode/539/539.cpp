class Solution {
public:
    int solve(const string& s) {
        int h = stoi(s.substr(0,2));
        int m = stoi(s.substr(3));
        return h*60+m;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = (int)timePoints.size();
        vector<int> result(2*n);
        for (int i = 0, j = 0; i < n; ++i) {
            result[j] = solve(timePoints[i]);
            ++j;
            result[j] = result[j-1]+60*24;
            ++j;
        }
        sort(result.begin(),result.end());
        int minVal = numeric_limits<int>::max();
        for (int i = 1; i < 2*n; ++i) {
            minVal = min(minVal, result[i] - result[i-1]);
        }
        return minVal;
    }
};