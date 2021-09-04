constexpr int MAXN = 2005;
constexpr int INF = 0x3f3f3f3f;

class LockingTree {
private:
    vector<int> parent;
    int n;
    int locked[MAXN];
    vector<int> AL[MAXN];
    bool hasLockedDes;
public:
    LockingTree(vector<int>& parent) : parent(parent) {
        memset(locked, 0x3f, sizeof locked);
        memset(AL, 0, sizeof AL);
        n = (int)parent.size();
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                AL[parent[i]].emplace_back(i);
            }
        }
    }
    bool lock(int num, int user) {
        if (locked[num] == INF) {
            locked[num] = user;
            return true;
        }
        return false;
    }
    bool unlock(int num, int user) {
        if (locked[num] == user) {
            locked[num] = INF;
            return true;
        }
        return false;
    }
    void dfs(int u, int user) {
        if (hasLockedDes) {
            return;
        }
        for (const auto &v : AL[u]) {
            if (locked[v] != INF) {
                hasLockedDes = true;
                return;
            }
            dfs(v, user);
        }
    }
    void dfs2(int u, int user) {
        for (const auto &v : AL[u]) {
            if (locked[v] != INF) {
                locked[v] = INF;
            }
            dfs2(v, user);
        }
    }
    bool upgrade(int num, int user) {
        // Check if the node is unlocked
        if (locked[num] != INF) {
            return false;
        }
        // It does not have any locked ancestors
        int temp = num;
        while (true) {
            temp = parent[temp];
            if (temp == -1) {
                break;
            }
            // locked ancestors
            if (locked[temp] != INF) {
                return false;
            }
        }
        // It has at least one locked descendant (by any user)
        hasLockedDes = false;
        dfs(num, user);
        if (hasLockedDes) {
            locked[num] = user;
            dfs2(num, user);
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */