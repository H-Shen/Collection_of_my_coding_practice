using ll = long long;

constexpr ll MAXN = 1e5;

class Solution {
public:
    // greedy
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) {
            return vector<ll>{};
        }
        ll n = MAXN;
        while (n*(n+1)>= finalSum) {
            --n;
        }
        ll temp;
        vector<ll> result;
        while (true) {
            temp = finalSum - n*(n+1);
            if (!(temp % 2 == 0 && temp >= 2 && temp <= 2*n)) {
                result.resize(n);
                for (ll i = 1; i <= n; ++i) {
                    result[i-1] = i*2;
                }
                result.emplace_back(temp);
                break;
            }
            --n;
        }
        return result;
    }
};