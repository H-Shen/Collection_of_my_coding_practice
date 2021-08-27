class Solution {
public:
    int getDist(int i0, int j0, int i1, int j1) {
        return abs(i0-i1) + abs(j0-j1);
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        for (const auto &i : nuts) {
            sum += getDist(i[0],i[1],tree[0],tree[1]);
        }
        int minDist = numeric_limits<int>::max();
        int n = (int)nuts.size();
        int dist, temp;
        for (int i = 0; i < n; ++i) {
            temp = getDist(nuts[i][0],nuts[i][1],tree[0],tree[1]);
            dist = getDist(squirrel[0],squirrel[1],nuts[i][0],nuts[i][1]) + temp + 2*(sum-temp);
            minDist = min(minDist, dist);
        }
        return minDist;
    }
};