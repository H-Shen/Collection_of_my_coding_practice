class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // S+2*a = sum
        // S+a+b=(1+n^2)*n^2/2
        using ll = long long;
        ll a, b;
        ll sum = 0;
        unordered_set<int> uniqueElements;
        for (const auto &i : grid) {
            for (const auto &j : i) {
                if (uniqueElements.count(j) > 0) {
                    a = j;
                }
                else {
                    uniqueElements.insert(j);
                }
                sum += j;
            }
        }
        ll n = (ll)grid.size();
        b = (((1+n*n)*n*n)>>1) - a - (sum - 2*a);
        return vector<int>{(int)a,(int)b};
    }
};