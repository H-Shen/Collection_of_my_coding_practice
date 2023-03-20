constexpr int STEPS = 8;
const int dx[] = {1,2,2,-1,-1,-2,-2,1};
const int dy[] = {2,1,-1,2,-2,-1,1,-2};

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = (int)grid.size();
        int total = n*n;
        vector<pair<int,int>> pos(total);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]].first = i;
                pos[grid[i][j]].second = j;
            }
        }
        int last_r, last_c, cur_r, cur_c, new_r, new_c;
        bool hasAns;
        for (int i = 1; i < total; ++i) {
            hasAns = false;
            last_r = pos[i-1].first;
            last_c = pos[i-1].second;
            cur_r = pos[i].first;
            cur_c = pos[i].second;
            for (int step = 0; step < STEPS; ++step) {
                new_r = last_r + dx[step];
                new_c = last_c + dy[step];
                if (new_r == cur_r && new_c == cur_c) {
                    hasAns = true;
                    break;
                }
            }
            if (!hasAns) {
                return false;
            }
        }
        return true;
    }
};