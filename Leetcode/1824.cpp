class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    int n;
    vector<vector<int> > dist;
    bool check(int i, int j, const vector<int>& obstacles) {
        return obstacles[j] == 0 || obstacles[j] != i+1;
    }
    void dequeBfs(const vector<int>&A) {
        constexpr int INF = 0x3f3f3f3f;
        dist.resize(3, vector<int>(n, INF));
        dist[1][0] = 0;
        deque<pair<int, int> > dq;
        dq.push_front({1, 0});
        int i,j,new_i,new_j;
        while (!dq.empty()) {
            i = dq.front().first;
            j = dq.front().second;
            dq.pop_front();
            if (j == n - 1) break;
            //
            new_i = i;
            new_j = j+1;
            if (new_j >= 0 && new_j < n && check(new_i,new_j,A)) {
                if (dist[new_i][new_j] > dist[i][j]) {
                    dist[new_i][new_j] = dist[i][j];
                    dq.push_front({new_i,new_j});
                }
            }
            //
            for (int step = -2; step <= 2; ++step) {
                if (step == 0) continue;
                new_i = i + step;
                new_j = j;
                if (new_i >= 0 && new_i < 3 && check(new_i,new_j,A)) {
                    if (dist[new_i][new_j] > dist[i][j] + 1) {
                        dist[new_i][new_j] = dist[i][j] + 1;
                        dq.push_back({new_i,new_j});
                    }
                }
            }
        }
    }
    int minSideJumps(vector<int>& A) {
        n = (int)A.size();
        dequeBfs(A);
        return min(dist[0][n-1],min(dist[1][n-1],dist[2][n-1]));
    }
};