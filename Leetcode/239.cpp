template<typename T>
struct Rmq {
    vector<T> v;
    int n;
    static constexpr int BLOCK_SIZE = 30;
    vector<int> mask, t;

    int op(int x, int y) {
        return v[x] < v[y] ? y : x;
    }
    int lsb(int x) {
        return x & -x;
    }
    int msb_index(int x) {
        return __builtin_clz(1) - __builtin_clz(x);
    }
    int small(int r, int size = BLOCK_SIZE) {
        int dist_from_r = msb_index(mask[r] & ((1 << size) - 1));

        return r - dist_from_r;
    }

    explicit Rmq(const vector<T> &v_) : v(v_), n(v.size()), mask(n), t(n) {
        int curr_mask = 0;
        for (int i = 0; i < n; i++) {
            curr_mask = (curr_mask << 1) & ((1 << BLOCK_SIZE) - 1);

            while (curr_mask > 0 and
                   op(i, i - msb_index(lsb(curr_mask))) == i) {
                curr_mask ^= lsb(curr_mask);
            }
            curr_mask |= 1;
            mask[i] = curr_mask;
        }
        for (int i = 0; i < n / BLOCK_SIZE; i++) t[i] = small(BLOCK_SIZE * i + BLOCK_SIZE - 1);
        for (int j = 1; (1 << j) <= n / BLOCK_SIZE; j++)
            for (int i = 0; i + (1 << j) <= n / BLOCK_SIZE; i++)
                t[n / BLOCK_SIZE * j + i] = op(t[n / BLOCK_SIZE * (j - 1) + i],
                                               t[n / BLOCK_SIZE * (j - 1) + i + (1 << (j - 1))]);
    }
    T query(int l, int r) {
        if (r - l + 1 <= BLOCK_SIZE) return v[small(r, r - l + 1)];
        int ans = op(small(l + BLOCK_SIZE - 1), small(r));
        int x = l / BLOCK_SIZE + 1, y = r / BLOCK_SIZE - 1;
        if (x <= y) {
            int j = msb_index(y - x + 1);
            ans = op(ans,
                     op(t[n / BLOCK_SIZE * j + x], t[n / BLOCK_SIZE * j + y - (1 << j) + 1]));
        }
        return v[ans];
    }
};

class Solution {
public:
    Solution() {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
    }
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        Rmq rmq(nums);
        int n = (int)nums.size();
        vector<int> result(n - k + 1);
        for (int i = k; i <= n; ++i) {
            result.at(i - k) = rmq.query(i - k, i - 1);
        }
        return result;
    }
};