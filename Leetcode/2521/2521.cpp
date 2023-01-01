constexpr int MAXN = 1003;

vector<int> primes;

bool isPrime(int n) {
    if (n <= 1) return false;
    else if (n == 2) return true;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void init() {
    if (!primes.empty()) {
        return;
    }
    for (int i = 2; i < MAXN; ++i) {
        if (isPrime(i)) {
            primes.emplace_back(i);
        }
    }
}

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        init();
        unordered_set<int> unset(primes.begin(),primes.end());
        int cnt = 0;
        for (auto&i : nums) {
            for (auto it = unset.begin(); it != unset.end();) {
                if (i % (*it) == 0) {
                    it = unset.erase(it);
                    ++cnt;
                }
                else {
                    ++it;
                }
            }
        }
        return cnt;
    }
};