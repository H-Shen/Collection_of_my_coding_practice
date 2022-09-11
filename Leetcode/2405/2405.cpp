class Solution {
public:
    int partitionString(string s) {
        int counter = 0;
        unordered_set<char> vis;
        for (const auto &i : s) {
            if (vis.count(i) > 0) {
                ++counter;
                vis.clear();
            }
            vis.insert(i);
        }
        if (!vis.empty()) {
            ++counter;
        }
        return counter;
    }
};