constexpr int MAXN = 305;
bitset<MAXN> vis[MAXN];

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        for (auto&i : vis) {
            i.reset();
        }
        int x,y,r;
        for (auto& c : circles) {
            x = c[0];
            y = c[1];
            r = c[2];
            for (int i = x-r; i <= x+r; ++i) {
                for (int j = y-r; j <= y+r; ++j) {
                    if ((i-x)*(i-x)+(j-y)*(j-y) <= r*r) {
                        vis[i][j] = true;
                    }
                }
            }
        }
        int counter = 0;
        for (auto&i : vis) {
            counter += (int)i.count();
        }
        return counter;
    }
};