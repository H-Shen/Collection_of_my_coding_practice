class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = (int)rocks.size();
        vector<pair<int,int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].first = capacity[i];
            vec[i].second = rocks[i];
        }
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.first - l.second < r.first - r.second;
        });
        int counter = 0;
        int temp;
        for (int i = 0; i < n; ++i) {
            temp = vec[i].first - vec[i].second;
            if (additionalRocks >= temp) {
                additionalRocks -= temp;
                ++counter;
            }
            else {
                break;
            }
        }
        return counter;
    }
};