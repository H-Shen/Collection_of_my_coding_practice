class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        constexpr int STEPS = 8;
        constexpr int SIDE = 8;
        const int dx[] = {0,0,-1,1,-1,1,-1,1};
        const int dy[] = {1,-1,0,0,-1,1,1,-1};
        
        int r = king[0];
        int c = king[1];
        bitset<SIDE> vis[SIDE];
        for (const auto &i : queens) {
            vis[i[0]][i[1]] = true;
        }
        vector<vector<int> > ans;
        int new_r, new_c;
        for (int i = 0; i < STEPS; ++i) {
            new_r = r;
            new_c = c;
            while (true) {
                new_r += dx[i];
                new_c += dy[i];
                if (!(new_r >= 0 && new_r < SIDE && new_c >=0 && new_c < SIDE)) {
                    break;
                }
                if (vis[new_r][new_c]) {
                    ans.emplace_back(vector<int>{new_r, new_c});
                    break;
                }
            }
        }
        return ans;
    }
};