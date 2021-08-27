namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}


namespace EulerPrimeSieve {

    constexpr int MAXN = 100005;
    int prime[MAXN] = {0};
    int num_prime = 0;
    bitset<MAXN> isNotPrime;
    bool hasSieved = false;
    
    void init() {
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = true;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

class Solution {
public:
    void getPrimeFactors(int n, unordered_map<int, vector<int> > &primes2val) {
        int nCopy = n;
        for (int i = 0; i < EulerPrimeSieve::num_prime; ++i) {
            while (n % EulerPrimeSieve::prime[i] == 0) {
                primes2val[EulerPrimeSieve::prime[i]].emplace_back(nCopy);
                n /= EulerPrimeSieve::prime[i];
            }
            if (n == 1) {
                break;
            }
        }
    }
    int largestComponentSize(vector<int>& A) {
        if (!EulerPrimeSieve::hasSieved) {
            EulerPrimeSieve::init();
            EulerPrimeSieve::hasSieved = true;
        }
        int n = *max_element(A.begin(), A.end());
        DSU::init(n);
        unordered_map<int, vector<int> > primes2val;
        for (const auto &i : A) {
            if (i > 1) {
                getPrimeFactors(i, primes2val);
            }
        }
        for (const auto &[k, v] : primes2val) {
            if (v.size() > 1) {
                for (size_t i = 1; i != v.size(); ++i) {
                    DSU::merge(v.at(i), v.at(i - 1));
                }
            }
        }
        unordered_set<int> groups;
        for (const auto &i : A) {
            groups.insert(DSU::find(i));
        }
        int maxSize = -1;
        for (const auto &i : groups) {
            maxSize = max(maxSize, DSU::Size[i]);
        }
        return maxSize;
    }
};