constexpr int MAXN = 1e5+5;

struct Interval {
    int left = -1;
    int right = -1;
};

class Solution {
public:
    // O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // get max right-bound
        int maxVal = 0;
        for (auto&i : intervals) {
            maxVal = max(maxVal, i[1]);
        }
        maxVal = max(maxVal, newInterval[1]);
        vector<int> diff(maxVal + 5);
        // collect all isolated nodes
        vector<int> single;
        for (auto&i : intervals) {
            if (i[0] == i[1]) {
                single.emplace_back(i[0]);
            }
        }
        if (newInterval[0] == newInterval[1]) {
            single.emplace_back(newInterval[0]);
        }
        // diff the diff array
        int l, r;
        for (auto&i : intervals) {
            if (i[0] != i[1]) {
                l = i[0];
                r = i[1];
                ++diff[l];
                --diff[r];
            }
        }
        if (newInterval[0] != newInterval[1]) {
            l = newInterval[0];
            r = newInterval[1];
            ++diff[l];
            --diff[r];
        }
        // restore
        for (int i = 1; i < (int)diff.size(); ++i) {
            diff[i] += diff[i-1];
        }
        vector<Interval> mergedIntervals(diff.size());
        // get all new merged intervals
        l = -1;
        for (int i = 0; i < (int)diff.size(); ++i) {
            if (diff[i] > 0) {
                if (l == -1) {
                    l = i;
                }
                r = i;
            }
            else {
                if (l != -1) {
                    mergedIntervals[l].left = l;
                    mergedIntervals[l].right = r+1;
                    l = -1;
                }
            }
        }
        if (l != -1) {
            mergedIntervals[l].left = l;
            mergedIntervals[l].right = r+1;
        }
        // process isolated nodes
        bitset<MAXN> vis;
        for (auto&i : mergedIntervals) {
            if (i.left != -1) {
                for (int j = i.left; j <= i.right; ++j) {
                    vis[j] = true;
                }
            }
        }
        while (!single.empty()) {
            if (!vis[single.back()]) {
                mergedIntervals[single.back()].left = single.back();
                mergedIntervals[single.back()].right = single.back();
            }
            single.pop_back();
        }
        // since all start points are unique, we can sort intervals linearly
        vector<vector<int>> ans;
        for (auto&i : mergedIntervals) {
            if (i.left != -1) {
                ans.emplace_back(vector<int>{i.left,i.right});
            }
        }
        return ans;
    }
};