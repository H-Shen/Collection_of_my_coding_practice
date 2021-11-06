constexpr int STEPS = 4;
constexpr int MAXN = 305;

// 0: up 1: right 2: down 3: left
void turnRight(int& dir) {
    if (dir == 3) {
        dir = 0;
    }
    else {
        ++dir;
    }
}

void nextStep(int dir, int i, int j, int& new_i, int& new_j) {
    new_i = i;
    new_j = j;
    switch (dir) {
        case 0:
            --new_i;
            break;
        case 1:
            ++new_j;
            break;
        case 2:
            ++new_i;
            break;
        case 3:
            --new_j;
            break;
        default:
            break;
    }
}

bool vis[MAXN][MAXN][STEPS];

class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        memset(vis, 0, sizeof vis);
        int cur_i = 0, cur_j = 0, dir = 1;
        int new_i, new_j;
        int counter = 0;
        int n = (int)room.size();
        int m = (int)room[0].size();
        vis[cur_i][cur_j][dir] = true;
        ++counter;
        bool has_visited;
        while (true) {
            nextStep(dir, cur_i, cur_j, new_i, new_j);
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && room[new_i][new_j] == 0) {
                if (vis[new_i][new_j][dir]) {
                    break;
                }
                vis[new_i][new_j][dir] = true;
                cur_i = new_i;
                cur_j = new_j;
                has_visited = false;
                for (int step = 0; step < STEPS; ++step) {
                    if (step != dir && vis[cur_i][cur_j][step]) {
                        has_visited = true;
                        break;
                    }
                }
                if (!has_visited) {
                    ++counter;
                }
            }
            else {
                turnRight(dir);
                if (vis[cur_i][cur_j][dir]) {
                    break;
                }
                vis[cur_i][cur_j][dir] = true;
            }
        }
        return counter;
    }
};