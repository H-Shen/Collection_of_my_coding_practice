class Solution {
public:
    unordered_set<string> de;
    unordered_map<string, int> dist;
    int bfs(const string &target) {
        constexpr int SLOTS = 4;
        queue<string> q;
        q.push("0000");
        dist["0000"] = 0;
        string u, u_copy;
        while (!q.empty()) {
            u = q.front();
            if (u == target) {
                return dist[u];
            }
            u_copy = u;
            q.pop();
            for (int i = 0; i < SLOTS; ++i) {
                if (u[i] >= '1' && u[i] <= '8') {
                    ++u[i];
                    if (de.find(u) == de.end() && dist.find(u) == dist.end()) {
                        dist[u] = dist[u_copy] + 1;
                        q.push(u);
                    }
                    --u[i];
                    --u[i];
                    if (de.find(u) == de.end() && dist.find(u) == dist.end()) {
                        dist[u] = dist[u_copy] + 1;
                        q.push(u);
                    }
                    ++u[i];
                }
                else if (u[i] == '9') {
                    u[i] = '8';
                    if (de.find(u) == de.end() && dist.find(u) == dist.end()) {
                        dist[u] = dist[u_copy] + 1;
                        q.push(u);
                    }
                    u[i] = '0';
                    if (de.find(u) == de.end() && dist.find(u) == dist.end()) {
                        dist[u] = dist[u_copy] + 1;
                        q.push(u);
                    }
                    u[i] = '9';
                }
                else if (u[i] == '0') {
                    u[i] = '1';
                    if (de.find(u) == de.end() && dist.find(u) == dist.end()) {
                        dist[u] = dist[u_copy] + 1;
                        q.push(u);
                    }
                    u[i] = '9';
                    if (de.find(u) == de.end() && dist.find(u) == dist.end()) {
                        dist[u] = dist[u_copy] + 1;
                        q.push(u);
                    }
                    u[i] = '0';
                }
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        for (const auto &i : deadends) {
            if (i == "0000") return -1;
            de.insert(i);
        }
        return bfs(target);
    }
};