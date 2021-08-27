constexpr int N = 1e4+5;
constexpr int MAXN = 1e5+5;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<> > unoccupied;
        for (int i = 0; i < N; ++i) {
            unoccupied.push(i);
        }
        vector<vector<int> > arrival(MAXN);
        vector<vector<int> > leaving(MAXN);
        vector<int> sits(N, -1);
        int n = (int)times.size();
        for (int i = 0; i < n; ++i) {
            arrival[times[i][0]].emplace_back(i);
            leaving[times[i][1]].emplace_back(i);
        }
        for (int i = 0; i < MAXN; ++i) {
            // leave
            if (!leaving[i].empty()) {
                for (const auto &j : leaving[i]) {
                    unoccupied.push(sits[j]);
                }
            }
            // arrive
            if (!arrival[i].empty()) {
                for (const auto &j : arrival[i]) {
                    sits[j] = unoccupied.top();
                    if (j == targetFriend) {
                        return sits[j];
                    }
                    unoccupied.pop();
                }  
            }
        }
        return -1;
    }
};