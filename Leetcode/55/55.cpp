struct BIT {
    vector<int> t1,t2;
    int N;
    int lowbit(int x) {
        return x & (-x);
    }
    BIT(int n) : N(n+1) {
        t1.resize(N);
        t2.resize(N);
    }
    int sum(vector<int>& t, int n) {
        int a(0);
        while (n) {
            a += t[n];
            n -= lowbit(n);
        }
        return a;
    }
    int rsum(int n) {
        return sum(t1,n)*n - sum(t2,n);
    }
    int rsum(int l, int r) {
        return rsum(r)-rsum(l-1);
    }
    void upd(vector<int>& t, int n, int val) {
        while (n < N) {
            t[n] += val;
            n += lowbit(n);
        }
    }
    void rupd(int l, int r, int val) {
        upd(t1, l, val);
        upd(t1, r+1, -val);
        upd(t2, l, val*(l-1));
        upd(t2, r+1, -val*r);
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        // greedy (update the interval each time)
        BIT bit(n);
        bit.rupd(1, nums[0]+1, 1);
        int l,r;
        for (int i = 0; i < n; ++i) {
            if (bit.rsum(i+1, i+1) > 0) {
                l = max(1, i+1-nums[i]+1);
                r = min(nums[i]+(i+1), n);
                bit.rupd(l,r,1);
            }
            else {
                break;
            }
            // prune
            if (bit.rsum(n,n) > 0) {
                return true;
            }
        }
        return false;
    }
};