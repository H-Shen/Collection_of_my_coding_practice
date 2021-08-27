using ll = long long;

class Solution {
public:
    unordered_map<ll, int> f(ll n) {
        unordered_map<ll, int> s;
        while (n > 0) {
            ++s[n % 10];
            n /= 10;
        }
        return s;
    }
    bool reorderedPowerOf2(int N) {
        // pre
        vector<unordered_map<ll, int> > A;
        ll cur = 1;
        while (A.size() <= 32) {
            A.emplace_back(f(cur));
            cur *= 2;
        }
        auto stats = f(N);
        for (const auto &i : A) {
            if (i == stats) return true;
        }
        return false;
    }
};