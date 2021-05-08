class Solution {
public:
    int countElements(vector<int>& arr) {
        constexpr int MAXN = 1005;
        int stats[MAXN]{};
        for (const auto &i : arr) {
            ++stats[i];
        }
        int counter = 0;
        for (int i = 0; i <= MAXN - 5; ++i) {
            if (stats[i] && stats[i+1]) {
                counter += stats[i];
            }
        }
        return counter;
    }
};