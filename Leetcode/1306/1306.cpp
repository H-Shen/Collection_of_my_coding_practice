class Solution {
public:
    bool has_ans = false;
    vector<bool> vis;
    void go(vector<int> &arr, int start) {
        try {
            if (arr.at(start) == 0) {
                has_ans = true;
                return;
            }
            if (vis.at(start)) {
                return;
            }
            vis.at(start) = true;
            go(arr, start + arr.at(start));
            go(arr, start - arr.at(start));
        } catch (...) { }
    }
    bool canReach(vector<int>& arr, int start) {
        vis.resize(arr.size(), false);
        go(arr, start);
        return has_ans;
    }
};