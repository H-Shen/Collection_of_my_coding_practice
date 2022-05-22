using ll = long long;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = (int)dist.size();
        vector<pair<ll,ll>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].first = dist[i];
            vec[i].second = speed[i];
        }
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.first*r.second < l.second*r.first;
        });
        int counter = 0;
        double currentTime = 0.0;
        for (int i = 0; i < n;) {
            if (currentTime < vec[i].first*1.0/vec[i].second) {
                ++counter;
                ++i;
                currentTime += 1.0;
            }
            else {
                break;
            }
        }
        return counter;
    }
};