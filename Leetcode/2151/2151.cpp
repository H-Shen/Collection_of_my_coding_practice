constexpr int MAXN = 16;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = (int)statements.size();
        int total = 1<<n;
        int maxGood = 0;
        bool contra;
        for (int i = 0; i < total; ++i) {
            bitset<MAXN> bs(i); // 1: good 0: bad
            contra = false;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (bs[j] && statements[j][k] == 0 && bs[k]) {
                        contra = true;
                        break;
                    }
                    if (bs[j] && statements[j][k] == 1 && !bs[k]) {
                        contra = true;
                        break;
                    }
                    
                }
                if (contra) break;
            }
            if (!contra) {
                maxGood = max(maxGood, (int)bs.count());
            }
        }
        return maxGood;
    }
};