/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // 离散化
        unordered_map<int,int> unmap;
        for (const auto &i : schedule) {
            for (const auto &j : i) {
                unmap[j.start] = 0;
                unmap[j.end] = 0;
            }
        }
        int length = (int)unmap.size();
        vector<int> vec(length);
        int index = 0;
        for (const auto &[k,v] : unmap) {
            vec[index++] = k;
        }
        sort(vec.begin(),vec.end());
        for (int i = 0; i < length; ++i) {
            unmap[vec[i]] = i;
        }
        // 差分数组
        vector<int> diff(length+1);
        int l, r;
        for (const auto &i : schedule) {
            for (const auto &j : i) {
                l = unmap[j.start];
                r = unmap[j.end];
                --r;
                diff[l] += 1;
                diff[r+1] -= 1;
            }
        }
        vector<int> original(length-1);
        for (int i = 0; i < length-1; ++i) {
            if (i == 0) {
                original[i] = diff[i];
            } else {
                original[i] = original[i-1] + diff[i];
            }
        }
        vector<Interval> ans;
        // 还原
        int startIndex = -1;
        int endIndex = -1;
        for (int i = 0; i < length-1; ++i) {
            if (original[i] == 0) {
                if (endIndex == -1) {
                    endIndex = i;
                    startIndex = i;
                }
                else {
                    ++endIndex;
                }
            }
            else {
                if (endIndex != -1) {
                    l = startIndex;
                    r = endIndex + 1;
                    ans.emplace_back(vec[l],vec[r]);
                    startIndex = -1;
                    endIndex = -1;
                }
            }
        }
        if (endIndex != -1) {
            l = startIndex;
            r = endIndex + 1;
            ans.emplace_back(vec[l],vec[r]);
        }
        return ans;
    }
};