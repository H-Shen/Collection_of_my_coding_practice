constexpr int MAXN = 1e3+5;
bitset<MAXN> al[MAXN];

class Solution {
public
    // O(n^3)
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        for (auto&i : al) i.reset();
        int u,v;
        for (auto&i : corridors) {
            al[i[0]][i[1]] = true;
            al[i[1]][i[0]] = true;
        }
        int counter = 0;
        for (int i = 1; i <= n-2; ++i) {
            for (int j = i+1; j <= n-1; ++j) {
                // prune
                if (al[i][j]) {
                    for (int k = j+1; k <= n; ++k) {
                        // prune again
                        if (al[i][k] && al[k][j]) ++counter;
                    }
                }
            }
        }
        return counter;
    }
};