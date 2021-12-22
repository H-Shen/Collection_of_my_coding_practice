constexpr int MAXN = 1e5+5;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

namespace Eratos {
    bitset<MAXN> prime;
    vector<int> primes;
    void init(int n) {
        prime.reset();
        prime.flip();
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                if ((long long)i*i < n) {
                    for (int j = i*i; j < n; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }
        decltype(primes)().swap(primes);
        for (int i = 0; i < n; ++i) {
            if (prime[i]) {
                primes.emplace_back(i);
            }
        }
    }
}

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(),nums.end());
        Eratos::init(maxValue + 1);
        DSU::init(maxValue);
        bitset<MAXN> vis;
        for (auto&i : nums) vis[i] = true;
        for (auto&i : Eratos::primes) {
            int temp = i;
            while (true) {
                if (temp > maxValue) break;
                if (vis[temp]) DSU::merge(temp, i);
                temp += i;
            }
        }
        vector<int> numsCopy(nums);
        sort(numsCopy.begin(),numsCopy.end());
        for (size_t i = 0; i != nums.size(); ++i) {
            if (numsCopy[i] != nums[i]) {
                if (DSU::find(numsCopy[i]) != DSU::find(nums[i])) {
                    return false;
                }
            }
        }
        return true;
    }
};