namespace EulerPrimeSieve {
    constexpr int MAXN = 1e6+5;
    bool initFlag = false;
    bitset<MAXN> isNotPrime;
    static void init() {
        if (initFlag) return;
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i]) {
                if (i > MAXN / i) {
                    continue;
                }
                for (int j = i * i; j < MAXN; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }
        initFlag = true;
    }
}

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        EulerPrimeSieve::init();
        vector<vector<int>> ans;
        for (int x = 2; x <= n; ++x) {
            if (!EulerPrimeSieve::isNotPrime[x] && x <= n-x && !EulerPrimeSieve::isNotPrime[n-x]) ans.emplace_back(vector<int>{x,n-x});
        }
        return ans;
    }
};