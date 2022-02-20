using ll = long long;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0) return vector<ll>{};
        ll n = num / 3 - 1;
        return vector<ll>{n,n+1,n+2};
    }
};