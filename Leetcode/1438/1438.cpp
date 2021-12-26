struct SparseTable {
    vector<vector<int> > spt, spt2;
    vector<int> Log2;
    int n, logn;
    explicit SparseTable(int n) : n(n) {
        Log2.resize(n + 5);
        Log2[1] = 0;
        Log2[2] = 1;
        for (int i = 3; i < n+5; ++i) {
            Log2[i] = Log2[i>>1] + 1;
        }
        logn = floor(Log2[n] + 2);
        spt.resize(n + 5, vector<int>(logn));
        spt2.resize(n + 5, vector<int>(logn));
    }
    void init() {
        for (int j = 1; j <= logn; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                spt.at(i).at(j) = max(spt.at(i).at(j - 1),spt.at(i + (1 << (j - 1))).at(j - 1));
                spt2.at(i).at(j) = min(spt2.at(i).at(j - 1),spt2.at(i + (1 << (j - 1))).at(j - 1));
            }
        }
    }
    int queryMax(int l, int r) {
        ++l; ++r;
        int s = Log2[r - l + 1];
        int ans = max(spt[l][s], spt[r - (1 << s) + 1][s]);
        return ans;
    }
    int queryMin(int l, int r) {
        ++l; ++r;
        int s = Log2[r - l + 1];
        int ans = min(spt2[l][s], spt2[r - (1 << s) + 1][s]);
        return ans;
    }
};

class Solution {
public:
    bool check(vector<int>& nums, SparseTable& st, int n, int limit, int length) {
        for (int i = 0, j = length-1; j < n; ++i, ++j) {
            if (st.queryMax(i,j) - st.queryMin(i,j) <= limit) return true; 
        }
        return false;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int n = (int)nums.size();
        SparseTable st(n);
        for (int i = 1; i <= n; ++i) {
            st.spt[i][0] = nums[i-1];
            st.spt2[i][0] = nums[i-1];
        }
        st.init();
        int l = 1;
        int r = n;
        int mid;
        int ans = 1;
        while (l <= r) {
            mid = l + ((r-l) >> 1);
            if (check(nums, st, n, limit, mid)) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};