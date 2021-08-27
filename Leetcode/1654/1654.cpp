class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        const int UPPER = 6005;
        const int DIRECTIONS = 2;
        const int INF = 0x3f3f3f3f;
        int dis[UPPER][DIRECTIONS];
        bitset<UPPER> forbid;
        
        // init
        for (const auto &i : forbidden) forbid[i] = true;
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        dis[0][1] = 0;

        queue<pair<int, int> > q;    // second: forward: 1 backward: 0
        q.push({0, 1});
        q.push({0, 0});

        pair<int, int> newNode, cur;
        while (!q.empty()) {
            cur = q.front();
            if (cur.first == x) {
                return dis[cur.first][cur.second];
            }
            q.pop();
            // jump forward
            newNode.second = 1;
            newNode.first = cur.first + a;
            if (newNode.first >= 0 && 
                newNode.first < UPPER &&
                !forbid[newNode.first] &&
                dis[newNode.first][newNode.second] == INF) {
                dis[newNode.first][newNode.second] = dis[cur.first][cur.second] + 1;
                q.push(newNode);
            }
            // jump backward (execute only if the last jump is forward)
            if (cur.second) {
                newNode.second = 0;
                newNode.first = cur.first - b;
                if (newNode.first >= 0 && 
                    newNode.first < UPPER &&
                    !forbid[newNode.first] &&
                    dis[newNode.first][newNode.second] == INF) {
                    dis[newNode.first][newNode.second] = dis[cur.first][cur.second] + 1;
                    q.push(newNode);
                }
            }
        }
        return -1;
    }
};