namespace DSU {
    vector<int> Size, father;
    int counter;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
        counter = 0;
    }
    int find(int x) {
        if (x != father[x]) {
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
        --counter;
        if (Size[x] > Size[y]) {
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

constexpr int STEPS = 4;
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};
vector<vector<int>> M;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        decltype(M)().swap(M);
        M.resize(m, vector<int>(n));
        DSU::init(m*n);
        int length = (int)positions.size();
        vector<int> ans(length);
        int new_i,new_j;
        for (int i = 0; i < length; ++i) {
            if (M[positions[i][0]][positions[i][1]] == 0) {
                M[positions[i][0]][positions[i][1]] = 1;
                ++DSU::counter;
                for (int step = 0; step < STEPS; ++step) {
                    new_i = positions[i][0]+dx[step];
                    new_j = positions[i][1]+dy[step];
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && M[new_i][new_j] == 1) {
                        DSU::merge(positions[i][0]*n+positions[i][1],new_i*n+new_j);
                    }
                }
            }
            ans[i] = DSU::counter;
        }
        return ans;
    }
};