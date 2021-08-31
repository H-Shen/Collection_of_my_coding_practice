namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
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
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

constexpr int STREETS = 6;
constexpr int STEPS = 4;    // 0: up 1: down 2: left 3: right
constexpr int UP = 0;
constexpr int DOWN = 1;
constexpr int LEFT = 2;
constexpr int RIGHT = 3;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

vector<int> vec[STREETS+1][STEPS];

class Solution {
public:
    void pre() {
        vec[1][LEFT] = {1,4,6};
        vec[1][RIGHT] = {1,3,5};
        vec[2][UP] = {2,3,4};
        vec[2][DOWN] = {2,5,6};
        vec[3][LEFT] = {1,4,6};
        vec[3][DOWN] = {2,5,6};
        vec[4][RIGHT] = {1,3,5};
        vec[4][DOWN] = {2,5,6};
        vec[5][UP] = {2,3,4};
        vec[5][LEFT] = {1,4,6};
        vec[6][UP] = {2,3,4};
        vec[6][RIGHT] = {1,3,5};
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        pre();
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        DSU::init(n*m);
        int new_i,new_j;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i+dx[step];
                    new_j = j+dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                        for (const auto &k : vec[grid[i][j]][step]) {
                            if (k == grid[new_i][new_j]) {
                                DSU::merge(i*m+j,new_i*m+new_j);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return DSU::find(0*m+0) == DSU::find((n-1)*m+(m-1));
    }
};