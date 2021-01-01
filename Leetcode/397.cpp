class Solution {
public:
    int integerReplacement(int n) {
        using ll = long long;
        unordered_map<ll, int> vis;
        queue<pair<ll, int> > q;
        q.push({n, 0});
        vis[n] = 0;
        pair<ll, int> cur;
        ll new_cur_first;
        int new_cur_second;
        
        while (!q.empty()) {
            cur = q.front();
            if (cur.first == 1) {
                return cur.second;
            }
            q.pop();
            if (cur.first % 2 == 0) {
                new_cur_first = cur.first / 2;
                new_cur_second = cur.second + 1;
                if (vis.find(new_cur_first) == vis.end() || vis[new_cur_first] > new_cur_second) {
                    vis[new_cur_first] = new_cur_second;
                    q.push({new_cur_first, new_cur_second});
                }
            } else {
                new_cur_first = cur.first + 1;
                new_cur_second = cur.second + 1;
                if (new_cur_first == 1) {
                    return new_cur_second;
                }
                if (vis.find(new_cur_first) == vis.end() || vis[new_cur_first] > new_cur_second) {
                    vis[new_cur_first] = new_cur_second;
                    q.push({new_cur_first, new_cur_second});
                }
                new_cur_first = cur.first - 1;
                new_cur_second = cur.second + 1;
                if (new_cur_first == 1) {
                    return new_cur_second;
                }
                if (vis.find(new_cur_first) == vis.end() || vis[new_cur_first] > new_cur_second) {
                    vis[new_cur_first] = new_cur_second;
                    q.push({new_cur_first, new_cur_second});
                }
            }
        }
        return -1;
    }
};