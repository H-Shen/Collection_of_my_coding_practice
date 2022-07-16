using ll = long long;

constexpr ll INF = -0x3f3f3f3f3f3f;
constexpr int MAXN = 7*1e4;
constexpr int START = 4*1e4;
ll A[MAXN];

class Solution {
public:
    inline
    bool inRange(multiset<ll>& ms, ll l, ll r) {
        if (l > r) {
            swap(l, r);
        }
        auto iter = ms.lower_bound(l);
        return (iter != ms.end() && *iter <= r);
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = (int)nums.size();
        // reset A[]
        int index;
        for (index = 0; index < START; ++index) {
            A[index] = INF;
        }
        for (int i = 0; i < n; ++i, ++index) {
            A[index] = nums[i];
        }
        for (;index < MAXN; ++index) {
            A[index] = INF;
        }
        // sliding window
        multiset<ll> ms;
        for (int i = START-k; i <= START+k; ++i) {
            if (A[i] != INF) {
                ms.insert(A[i]);
            }
        }
        int l = START-k, r = START+k, i = START;
        while (true) {
            ll lowerBound = A[i] - (ll)t;
            ll upperBound = A[i] + (ll)t;
            auto self = ms.find(A[i]);
            ms.erase(self);
            if (inRange(ms, lowerBound, upperBound)) {
                return true;
            }
            ms.insert(A[i]);
            if (A[l] != INF) {
                ms.erase(ms.find(A[l])); 
            }
            ++l;
            ++r;
            ++i;
            if (i < START + n) {
                if (A[r] != INF) {
                    ms.insert(A[r]);
                }
            }
            else {
                break;
            }
        }
        return false;
    }
};