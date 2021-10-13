using ll = long long;

constexpr ll MOD = 1e9+7;

template<typename T>
struct BIT {
    vector<T> t1, t2;
    int N;
    int lowbit(int i) {
        return i & (-i);
    }
    // index starts from 1
    BIT(int n) : N(n+5) {
        t1.resize(N);
        t2.resize(N);
    }
    T sum(const vector<T> &t, int n) {
        T a(0);
        while (n) {
            a += t[n];
            n -= lowbit(n);
        }
        return a;
    }
    T rsum(int n) {
        return sum(t1,n)*n-sum(t2,n);
    }
    T rsum(int l, int r) {
        return rsum(r)-rsum(l-1);
    }
    void upd(vector<T> &t, int n, T val) {
        while (n < N) {
            t[n] += val;
            n += lowbit(n);
        }
    }
    void rupd(int l, int r, T val) {
        upd(t1,l,val);
        upd(t1,r+1,-val);
        upd(t2,l,val*(l-1));
        upd(t2,r+1,-val*r);
    }
};

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        vector<int> A(n+1);
        for (int i = 0; i <= n; ++i) {
            A[i] = 2*pre[i] - i;
        }
        auto p = minmax_element(A.begin(),A.end());
        int minVal = *(p.first);
        int maxVal = *(p.second);
        BIT<int> bit(maxVal - minVal + 1);
        // mapping all values to [1...]
        int diff = (minVal > 0) ? 0 : -minVal + 1;
        ll counter = 0;
        bit.rupd(A[0]+diff, A[0]+diff, 1);    // update the frequency
        for (int r = 1; r <= n; ++r) {
            if (A[r]+diff >= 2) {
                counter += (ll)bit.rsum(1,A[r]+diff-1);
            }
            bit.rupd(A[r]+diff,A[r]+diff,1);
        }
        return (int)(counter % MOD);
    }
};