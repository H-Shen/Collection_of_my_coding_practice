class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        unordered_map<int,int> unmap;
        for (const auto &i : intervals) {
            for (const auto &j : i) {
                unmap[j] = 0;
            }
        }
        int index = 0;
        int length = (int)unmap.size();
        vector<int> vec(length);
        for (const auto &[i,j] : unmap) {
            vec[index++] = i;
        }
        sort(vec.begin(),vec.end());
        for (int i = 0; i < length; ++i) {
            unmap[vec[i]] = i;
        }
        vector<int> diff(length+1);
        int l, r;
        for (const auto &i : intervals) {
            l = unmap[i[0]];
            r = unmap[i[1]];
            ++diff[l];
            --diff[r];
        }
        vector<int> original(length-1);
        for (int i = 0; i < length-1; ++i) {
            if (i == 0) {
                original[i] = diff[i];
            } else {
                original[i] = original[i-1] + diff[i];
            }
        }
        return *max_element(original.begin(), original.end());
    }
};