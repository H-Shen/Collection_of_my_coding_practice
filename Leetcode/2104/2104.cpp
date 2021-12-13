using ll = long long;

struct SparseTable {
    vector<vector<ll> > sptMax, sptMin;
    vector<ll> Log2;
    int n, logn;
    explicit SparseTable(int n) : n(n) {
        Log2.resize(n + 5);
        Log2.at(1) = 0;
        Log2.at(2) = 1;
        for (int i = 3; i < n + 5; ++i)
            Log2.at(i) = Log2.at(i >> 1) + 1;
        logn = floor(log2(n) + 2);
        sptMax.resize(n + 5, vector<ll>(logn));
        sptMin.resize(n + 5, vector<ll>(logn));
    }
    void input(vector<int> &nums) {
        for (int i = 1; i <= n; ++i) {
            sptMax.at(i).at(0) = sptMin.at(i).at(0) = nums.at(i-1);
        }
    }
    void init() {
        for (int j = 1; j <= logn; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                sptMax.at(i).at(j) = max(sptMax.at(i).at(j - 1), sptMax.at(i + (1 << (j - 1))).at(j - 1));
                sptMin.at(i).at(j) = min(sptMin.at(i).at(j - 1), sptMin.at(i + (1 << (j - 1))).at(j - 1));
            }
        }
    }
    ll queryMax(int l, int r) {
        int s = Log2.at(r - l + 1);
        ll ans = max(sptMax.at(l).at(s), sptMax.at(r - (1 << s) + 1).at(s));
        return ans;
    }
    ll queryMin(int l, int r) {
        int s = Log2.at(r - l + 1);
        ll ans = min(sptMin.at(l).at(s), sptMin.at(r - (1 << s) + 1).at(s));
        return ans;
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = (int)nums.size();
        SparseTable st(n);
        st.input(nums);
        st.init();
        ll sum = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                sum += st.queryMax(l+1,r+1) - st.queryMin(l+1,r+1);
            }
        }
        return sum;
    }
};