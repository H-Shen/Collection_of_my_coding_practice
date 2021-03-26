class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int total = R*C;
        vector<vector<int> > result(total, vector<int>(2));
        int index = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                result[index][0] = i;
                result[index][1] = j;
                ++index;
            }
        }
        sort(result.begin(), result.end(), [&](const auto &l, const auto &r) {
            int dist1 = abs(l[0]-r0)+abs(l[1]-c0);
            int dist2 = abs(r[0]-r0)+abs(r[1]-c0);
            return dist1 < dist2;
        });
        return result;
    }
};