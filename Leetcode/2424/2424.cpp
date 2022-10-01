constexpr int MAXN = 1e5+5;

template<typename T>
struct BIT {
    vector<T> t1, t2;
    int N;
    int lowbit(int i) {
        return i & (-i);
    }
    // index starts from 1
    BIT(int n) : N(n+1) {
        t1.resize(N);
        t2.resize(N);
    }
    BIT() = default;
    T sum(vector<T> &t, int n) {
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

class LUPrefix {
private:
    BIT<int> t;
    bool firstFilled;
public:
    LUPrefix(int n) {
        t.N = MAXN;
        t.t1.resize(t.N);
        t.t2.resize(t.N);
        firstFilled = false;
    }
    
    void upload(int video) {
        t.rupd(video, video, 1);
        if (video == 1) {
            firstFilled = true;
        }
    }
    
    int longest() {
        if (!firstFilled) {
            return 0;
        }
        int l = 1;
        int r = t.N;
        int mid;
        int ans = -1;
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (t.rsum(1, mid) < mid) {
                r = mid - 1;
            } 
            else {
                ans = max(ans, mid);
                l = mid + 1;
            }
        }
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */