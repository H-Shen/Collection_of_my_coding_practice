namespace EulerPrimeSieve {

    const int MAXN = 1000005;
    int prime[MAXN] = {0};
    int num_prime = 0;
    bool isNotPrime[MAXN] = {true, true};

    // Generate the prime table from 1 to MAXN
    static void init() {
        if (num_prime > 0) {
            return;
        }
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
    vector<int> closestPrimes(int left, int right) {
        EulerPrimeSieve::init();
        cout << EulerPrimeSieve::num_prime << '\n';
        vector<int> ans = {-1,-1};
        int a, b;
        for (int i = 0; i < EulerPrimeSieve::num_prime-1; ++i) {
            a = EulerPrimeSieve::prime[i];
            b = EulerPrimeSieve::prime[i+1];
            if (left <= a && b <= right) {
                if (ans[0] == -1) {
                    ans[0] = a;
                    ans[1] = b;
                }
                else if (b-a < ans[1]-ans[0]) {
                    ans[0] = a;
                    ans[1] = b;
                }
            }
        }
        return ans;
    }
};