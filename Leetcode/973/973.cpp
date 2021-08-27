class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), [](const vector<int> &l, const vector<int> &r) {
            return l.front() * l.front() + l.back() * l.back() < r.front() * r.front() + r.back() * r.back();
        });
        return vector<vector<int> >(points.begin(), points.begin() + K);
    }
};