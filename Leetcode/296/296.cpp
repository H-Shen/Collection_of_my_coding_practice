class Solution {
public:
    int solve(const vector<pair<int,int> > &v, int i, int j) {
        int dist = 0;
        for (const auto &[y,x] : v) {
            dist += abs(i-y) + abs(j-x);
        }
        return dist;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector<int> vecX, vecY;
        vector<pair<int,int> > vec;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    vecX.emplace_back(j);   // frequency matters
                    vecY.emplace_back(i);
                    vec.emplace_back(i,j);
                }
            }
        }
        sort(vecX.begin(),vecX.end());
        sort(vecY.begin(),vecY.end());
        vector<int> ansX, ansY;
        if (vecX.size() % 2 == 0) {
            ansX.emplace_back(vecX[vecX.size()/2]);
            ansX.emplace_back(vecX[vecX.size()/2-1]);
        }
        else {
            ansX.emplace_back(vecX[(vecX.size()-1)/2]);
        }
        if (vecY.size() % 2 == 0) {
            ansY.emplace_back(vecY[vecY.size()/2]);
            ansY.emplace_back(vecY[vecY.size()/2-1]);
        }
        else {
            ansY.emplace_back(vecY[(vecY.size()-1)/2]);
        }
        int ans = numeric_limits<int>::max();
        for (const auto &x : ansX) {
            for (const auto &y : ansY) {
                ans = min(ans,solve(vec,y,x));
            }
        }
        return ans;
    }
};