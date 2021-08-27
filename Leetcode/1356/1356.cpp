class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int &l, const int &r) {
            int a = __builtin_popcount(l);
            int b = __builtin_popcount(r);
            if (a == b) return l < r;
            return a < b;
        });
        return arr;
    }
};