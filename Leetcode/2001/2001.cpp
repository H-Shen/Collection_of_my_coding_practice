using ll = long long;

struct myHashFunc {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        unordered_map<pair<int,int>, int, myHashFunc> unmap;
        int n = (int)rec.size();
        pair<int,int> p;
        int temp;
        for (int i = 0; i < n; ++i) {
            p.first = rec[i][0];
            p.second = rec[i][1];
            temp = gcd(p.first, p.second);
            p.first /= temp;
            p.second /= temp;
            ++unmap[p];
        }
        ll counter = 0;
        for (const auto &[k,v] : unmap) {
            ll temp = (ll)v;
            counter += (temp*(temp-1))>>1;
        }
        return counter;
    }
};