namespace EulerPrimeSieve {
    constexpr int MAXN = 1e5+5;
    bitset<MAXN> isNotPrime;
    vector<int> primes;
    bool hasInited = false;
    void init() {
        if (hasInited) {
            return;
        }
        hasInited = true;
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for (int i = 2; i < MAXN; ++i) {
            if (!isNotPrime[i]) {
                if (i > MAXN / i) continue;
                for (int j = i*i; j < MAXN; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }
        for (int i = 0; i < MAXN; ++i) {
            if (!isNotPrime[i]) {
                primes.emplace_back(i);
            }
        }
    }
}

class Solution {
public:
    unordered_set<int> vis;
    int solve(int n) {
        if (vis.count(n) > 0) {
            return n;
        }
        vis.insert(n);
        if (!EulerPrimeSieve::isNotPrime[n]) {
            return n;
        }
        int ans = 0;
        for (auto&i : EulerPrimeSieve::primes) {
            if (i > n) break;
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        return solve(ans);
    }
    int smallestValue(int n) {
        EulerPrimeSieve::init();
        vis.clear();
        return solve(n);
    }
};