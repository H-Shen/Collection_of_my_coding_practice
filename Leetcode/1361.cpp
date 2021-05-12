namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n+5,1);
        cc = n;
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
        --cc;
    }
}

vector<vector<int> > AL;
vector<int> inDegree, outDegree;

namespace Toposort {
    vector<int> vis;
    bool dfs(int u) {
        vis[u] = -1;
        for (const auto &v : AL[u]) {
            if (vis[v] < 0) {
                return false;
            }
            else if (vis[v] == 0) {
                if (!dfs(v)) {
                    return false;
                }
            }
        }
        vis[u] = 1;
        return true;
    }
    bool toposort(int n) {
        vector<int>().swap(vis);
        vis.resize(n);
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0) {
                if (!dfs(i)) {
                    return false;
                } 
            }
        }
        return true;
    }
}

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if (n == 1) {
            return true;
        }
        decltype(AL)().swap(AL);
        AL.resize(n);
        vector<int>().swap(inDegree);
        inDegree.resize(n);
        vector<int>().swap(outDegree);
        outDegree.resize(n);
        DSU::init(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                AL[i].emplace_back(leftChild[i]);
                ++inDegree[leftChild[i]];
                ++outDegree[i];
                DSU::merge(i, leftChild[i]);
            }
            if (rightChild[i] != -1) {
                AL[i].emplace_back(rightChild[i]);
                ++inDegree[rightChild[i]];
                ++outDegree[i];
                DSU::merge(i, rightChild[i]);
            }
        }
        //
        if (DSU::cc != 1) {
            return false;
        }
        //
        unordered_map<int,int> unmap;
        for (int i = 0; i < n; ++i) {
            ++unmap[inDegree[i]];
        }
        if (unmap.size() != 2) {
            return false;
        }
        if (unmap.find(0) == unmap.end() || unmap.find(1) == unmap.end()) {
            return false;
        }
        if (unmap[0] != 1) {
            return false;
        }
        //
        unmap.clear();
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] > 2) {
                return false;
            }
        }
        //
        if (!Toposort::toposort(n)) {
            return false;
        }
        //
        return true;
    }
};