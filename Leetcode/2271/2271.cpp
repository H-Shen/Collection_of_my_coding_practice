using ll = long long;

class Solution {
public:
    ll rangeSum(vector<ll>& pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end(),[](const auto&l, const auto&r){
            return l[0] < r[0];
        });
        int n = (int)tiles.size();
        vector<ll> pre(n);
        pre[0] = tiles[0][1] - tiles[0][0] + 1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + tiles[i][1] - tiles[i][0] + 1;
        }
        ll maxVal = 0;
        ll covered;
        for (int i = 0; i < n; ++i) {
            int left = tiles[i][0];
            int right = left+carpetLen-1;
            auto iter = --upper_bound(tiles.begin(),tiles.end(), vector<int>{right,0}, [](const auto&l, const auto&r){
                return l[0] < r[0];
            });
            if ((*iter)[1] <= right) {
                covered = rangeSum(pre, i, (int)(iter - tiles.begin()));
            }
            else {
                covered = rangeSum(pre, i, (int)(iter - tiles.begin()) - 1) + (right - (*iter)[0] + 1);
            }
            maxVal = max(maxVal, covered);
        }
        return (int)maxVal;
    }
};