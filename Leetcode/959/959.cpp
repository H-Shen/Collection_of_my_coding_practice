namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        decltype(father)().swap(father);
        decltype(Size)().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        --cc;
        Size[y] += Size[x];
        father[x] = y;
    }
}

struct Node {
    int l,r;
    char dir;
    Node() = default;
};

void mergeUp(Node& l, Node& r) {
    if (l.dir == ' ' && r.dir == ' ') {
        DSU::merge(l.l, r.r);
    }
    else if (l.dir == ' ' && r.dir == '/') {
        DSU::merge(l.l, r.r);
    }
    else if (l.dir == ' ' && r.dir == '\\') {
        DSU::merge(l.l, r.l);
    }
    else if (l.dir == '/' && r.dir == ' ') {
        DSU::merge(l.l, r.r);
    }
    else if (l.dir == '/' && r.dir == '/') {
        DSU::merge(l.l, r.r);
    }
    else if (l.dir == '/' && r.dir == '\\') {
        DSU::merge(l.l, r.l);
    }
    else if (l.dir == '\\' && r.dir == ' ') {
        DSU::merge(l.r, r.r);
    }
    else if (l.dir == '\\' && r.dir == '/') {
        DSU::merge(l.r, r.r);
    }
    else if (l.dir == '\\' && r.dir == '\\') {
        DSU::merge(l.r, r.l);
    }
}

void mergeLeft(Node& l, Node& r) {
    DSU::merge(l.l, r.r);
}

void mergeRight(Node& l, Node& r) {
    DSU::merge(l.r, r.l);
}

void mergeDown(Node& l, Node& r) {
    if (l.dir == ' ' && r.dir == ' ') {
        DSU::merge(l.r, r.l);
    }
    else if (l.dir == ' ' && r.dir == '/') {
        DSU::merge(l.r, r.l);
    }
    else if (l.dir == ' ' && r.dir == '\\') {
        DSU::merge(l.r, r.r);
    }
    else if (l.dir == '/' && r.dir == ' ') {
        DSU::merge(l.r, r.r);
    }
    else if (l.dir == '/' && r.dir == '/') {
        DSU::merge(l.r, r.l);
    }
    else if (l.dir == '/' && r.dir == '\\') {
        DSU::merge(l.r, r.r);
    }
    else if (l.dir == '\\' && r.dir == ' ') {
        DSU::merge(l.l, r.r);
    }
    else if (l.dir == '\\' && r.dir == '/') {
        DSU::merge(l.l, r.l);
    }
    else if (l.dir == '\\' && r.dir == '\\') {
        DSU::merge(l.l, r.r);
    } 
}

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = (int)grid.size();
        vector<vector<Node>> v(n, vector<Node>(n));
        DSU::init((n*n)<<1);
        int id = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == ' ') {
                    v[i][j].l = id;
                    v[i][j].r = id;
                    ++id;
                }
                else {
                    v[i][j].l = id;
                    ++id;
                    v[i][j].r = id;
                    ++id;
                }
                v[i][j].dir = grid[i][j];
            }
        }
        DSU::cc = id;
        int new_i, new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // up
                new_i = i-1;
                new_j = j;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                    mergeUp(v[i][j], v[new_i][new_j]);
                }
                // down
                new_i = i+1;
                new_j = j;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                    mergeDown(v[i][j], v[new_i][new_j]);
                }
                // left
                new_i = i;
                new_j = j-1;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                    mergeLeft(v[i][j], v[new_i][new_j]);
                }
                // right
                new_i = i;
                new_j = j+1;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                    mergeRight(v[i][j], v[new_i][new_j]);
                }
            }
        }
        return DSU::cc;
    }
};