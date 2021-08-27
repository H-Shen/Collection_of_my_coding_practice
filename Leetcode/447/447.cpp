class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = (int)points.size();
        long long counter = 0;
        int dist, x1, y1, x2, y2;
        unordered_map<int, int> unmap;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                x1 = points.at(i).at(0);
                y1 = points.at(i).at(1);
                x2 = points.at(j).at(0);
                y2 = points.at(j).at(1);
                dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
                ++unmap[dist];
            }
            for (const auto &[k, v] : unmap) {
                if (v > 1) {
                    counter += v * (v - 1); // A(v, 2)
                }
            }
            unmap.clear();
        }
        return (int)counter;
    }
};