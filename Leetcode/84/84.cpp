// Sparse Table
struct Node {
    int val, pos;
    Node(int val, int pos) : val(val), pos(pos) {}
    Node() = default;
};

bool cmp(const Node &l, const Node& r) {
    return l.val < r.val;
}

struct SparseTable {
    vector<vector<Node>> spt;
    vector<int> Log2;
    int n, logn;
    SparseTable(const vector<int>& vec) {
        n = (int)vec.size();
        // pre
        Log2.resize(n+5);
        Log2[1] = 0;
        Log2[2] = 1;
        for (int i = 3; i < n+5; ++i) {
            Log2[i] = Log2[i>>1]+1;
        }
        logn = floor(log2(n)+2);
        spt.resize(n+5, vector<Node>(logn));
        // input
        for (int i = 1; i <= n; ++i) {
            spt[i][0].val = vec[i-1];
            spt[i][0].pos = i;
        }
        // init
        for (int j = 1; j <= logn; ++j) {
            for (int i = 1; i+(1<<j)-1 <= n; ++i) {
                spt[i][j] = min(spt[i][j-1], spt[i+(1<<(j-1))][j-1], cmp);
            }
        }
    }
    const Node& rangeMin(int l, int r) const {
        int s = Log2[r-l+1];
        return min(spt[l][s], spt[r-(1<<s)+1][s], cmp);
    }
};

class Solution {
public:
    int ans;
    void solve(SparseTable& st, vector<int>& heights, int l, int r) {
        if (l > r) {
            return;
        }
        else if (l == r) {
            ans = max(ans,heights[l-1]);
            return;
        }
        // divide
        auto node = st.rangeMin(l, r);
        int mid = node.pos;
        solve(st, heights, l, mid-1);
        solve(st, heights, mid+1, r);
        // conquer
        ans = max(ans, node.val*(r-l+1));
    }
    // O(nlogn) + O(n) = O(nlogn)
    int largestRectangleArea(vector<int>& heights) {
        SparseTable st(heights);
        int n = (int)heights.size();
        ans = 0;
        solve(st, heights, 1, n);
        return ans;
    }
};