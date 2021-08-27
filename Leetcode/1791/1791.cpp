class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        constexpr int MAXN = 100005;
        bitset<MAXN> degree;
        for (const auto &i : edges) {
            if (degree[i.front()]) {
                return i.front();
            } else {
                degree[i.front()] = true;
            }
            if (degree[i.back()]) {
                return i.back();
            } else {
                degree[i.back()] = true;
            }
        }
        return -1;
    }
};