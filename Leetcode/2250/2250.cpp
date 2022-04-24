constexpr int MAXN = 10*1e4+5;
constexpr int MAXM = 1e2+5;

int A[MAXN][MAXM];

inline
void add(int i, int j, int x, int y, int val) {
    A[i][j] += val;
    A[x+1][y+1] += val;
    A[x+1][j] -= val;
    A[i][y+1] -= val;
}

inline
void restore(int max_x, int max_y) {
    for (int i = 1; i <= max_y; ++i) {
        A[0][i] = A[0][i-1] + A[0][i];
    }
    for (int i = 1; i <= max_x; ++i) {
        A[i][0] = A[i-1][0] + A[i][0];
    }
    for (int i = 1; i <= max_x; ++i) {
        for (int j = 1; j <= max_y; ++j) {
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    } 
}

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> all_x;
        int max_y = -1;
        all_x.emplace_back(0);
        for (auto&i : rectangles) {
            all_x.emplace_back(i[0]);
            max_y = max(max_y, i[1]);
        }
        for (auto&i : points) {
            all_x.emplace_back(i[0]);
            max_y = max(max_y, i[1]);
        }
        sort(all_x.begin(),all_x.end());
        all_x.erase(unique(all_x.begin(),all_x.end()),all_x.end());
        memset(A, 0, sizeof A);
        int x,y;
        for (auto& r : rectangles) {
            x = (int)(lower_bound(all_x.begin(),all_x.end(),r[0]) - all_x.begin());
            y = r[1];
            add(0,0,x,y,1);
        }
        int max_x = (int)all_x.size()-1;
        restore(max_x, max_y);
        int n = (int)points.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            x = (int)(lower_bound(all_x.begin(),all_x.end(),points[i][0]) - all_x.begin());
            y = points[i][1];
            result[i] = A[x][y];
        }
        return result;
    }
};