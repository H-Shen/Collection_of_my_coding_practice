class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return true;
        }
        // 离散化
        unordered_map<int,int> unmap;
        for (const auto &i : intervals) {
            for (const auto &j : i) {
                unmap[j] = 0;
            }
        }
        int length = (int)unmap.size();
        vector<int> vec(length);
        int index = 0;
        for (const auto &[i,j] : unmap) {
            vec[index++] = i;
        }
        sort(vec.begin(),vec.end());
        for (int i = 0; i < length; ++i) {
            unmap[vec[i]] = i;
        }
        // 差分数组
        vector<int> diff(length+1);
        int l, r;
        for (const auto &i : intervals) {
            l = unmap[i[0]];
            r = unmap[i[1]];
            ++diff[l];
            --diff[r];
        }
        // 还原
        vector<int> original(length-1);
        for (int i = 0; i < length-1; ++i) {
            if (i == 0) {
                original[i] = diff[i];
            } else {
                original[i] = original[i-1] + diff[i];
            }
            
        }
        for (int i = 0; i < length - 1; ++i) {
            if (original[i] > 1) {
                return false;
            }
        }
        return true;
    }
};