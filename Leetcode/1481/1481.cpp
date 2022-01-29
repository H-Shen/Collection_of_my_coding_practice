class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // use hashmap to count the freqency of each element
        unordered_map<int,int> unmap;
        for (auto&i : arr) {
            ++unmap[i];
        }
        deque<pair<int,int>> dq(unmap.begin(),unmap.end());
        // greedy
        sort(dq.begin(),dq.end(),[](const auto &l, const auto &r) {
            return l.second < r.second;
        });
        while (k > 0) {
            dq.front().second--;
            k--;
            if (dq.front().second == 0) {
                dq.pop_front();
            }
        }
        return (int)dq.size();
    }
};