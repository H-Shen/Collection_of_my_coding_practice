class Solution {
public:
    vector<vector<bool> > vis;
    void dfs(vector<vector<int>>& image, int r, int c, int n, int m, int oldColor) {
        constexpr int STEPS = 4;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        int new_r, new_c;
        for (int step = 0; step < STEPS; ++step) {
            new_r = r + dx[step];
            new_c = c + dy[step];
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && !vis.at(new_r).at(new_c) && image.at(new_r).at(new_c) == oldColor) {
                vis.at(new_r).at(new_c) = true;
                dfs(image, new_r, new_c, n, m, oldColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = (int)image.size();
        int m = (int)image.front().size();
        vis.resize(n, vector<bool>(m, false));
        vis.at(sr).at(sc) = true;
        dfs(image, sr, sc, n, m, image.at(sr).at(sc));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis.at(i).at(j)) {
                    image.at(i).at(j) = newColor;
                }
            }
        }
        return image;
    }
};