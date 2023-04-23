constexpr int MAXN = 105;
constexpr int GAP = 50;

class Solution {
public:
    inline
    bool fewerThanX(const vector<int>& pre, int l, int r, int x) const {
        if (l == 0) {
            return pre[r] < x;
        }
        return pre[r] - pre[l-1] < x;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = (int)nums.size();
        vector<int> pre(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                pre[i] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            pre[i] += pre[i-1];
        }
        int freq[MAXN]{};
        for (int i = 0; i < k; ++i) {
            ++freq[nums[i] + GAP];
        }
        vector<int> ans(n-k+1);
        for (int i = 0, j = k-1; ;) {
            if (fewerThanX(pre, i, j, x)) {
                ans[i] = 0;
            }
            else {
                for (int pos = 0, rank = 0; pos < MAXN;) {
                    if (freq[pos] > 0) {
                        if (rank + freq[pos] < x) {
                            rank += freq[pos];
                            ++pos;
                        }
                        else {
                            ans[i] = pos - GAP;
                            break;
                        }
                    }
                    else {
                        ++pos;
                    }
                }
            }
            // update
            ++j;
            if (j == n) {
                break;
            }
            ++freq[nums[j] + GAP];
            --freq[nums[i] + GAP];
            ++i;
        }
        return ans;
    }
};