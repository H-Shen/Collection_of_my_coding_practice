constexpr int MAXN = 102;

class Solution {
public: 
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> hashMap(MAXN);  // hashMap[i] = all lengths with height = i
        int n = (int)rectangles.size();
        int l, h;
        for (int i = 0; i < n; ++i) {
            l = rectangles[i][0];
            h = rectangles[i][1];
            hashMap[h].emplace_back(l);
        }
        for (auto&i : hashMap) {
            sort(i.begin(),i.end());
        }
        int m = (int)points.size();
        vector<int> result(m);
        for (int i = 0; i < m; ++i) {
            l = points[i][0];
            h = points[i][1];
            for (int j = h; j < MAXN; ++j) {
                result[i] += (int)(hashMap[j].size()) - (int)(lower_bound(hashMap[j].begin(),hashMap[j].end(),l) - hashMap[j].begin());
            }
        }
        return result;
    }
};