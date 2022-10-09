class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        unordered_map<int,int> unmap;
        int length = (int)logs.size();
        for (int i = 0; i < length; ++i) {
            if (i == 0) {
                unmap[logs[i][0]] = logs[i][1];
                continue;
            }
            int time = logs[i][1] - logs[i-1][1];
            if (unmap.count(logs[i][0]) == 0) {
                unmap[logs[i][0]] = time;
            }
            else {
                unmap[logs[i][0]] = max(unmap[logs[i][0]], time);
            }
        }
        vector<pair<int,int>> vec(unmap.begin(),unmap.end());
        return (*min_element(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (l.second == r.second) {
                return l.first < r.first;
            }
            return l.second > r.second;
        })).first;
    }
};