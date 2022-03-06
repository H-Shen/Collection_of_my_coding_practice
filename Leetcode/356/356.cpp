class Solution {
public:
    struct myHashFunc {
        size_t operator()(const pair<int,int>& o) const {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        }  
    };
    // 重复的点按一个点算
    // 分割线x = (x_min+x_max)/2.0
    bool isReflected(vector<vector<int>>& points) {
        int n = (int)points.size();
        int x_min = numeric_limits<int>::max();
        int x_max = numeric_limits<int>::min();
        unordered_set<pair<int,int>,myHashFunc> unset;
        for (auto&i : points) {
            x_min = min(x_min, i[0]);
            x_max = max(x_max, i[0]);
            unset.insert({i[0],i[1]});
        }
        double k = (x_min+x_max) / 2.0;
        pair<int,int> p;
        int x,y,new_x,new_y;
        while (!unset.empty()) {
            auto iter = unset.begin();
            x = iter->first;
            y = iter->second;
            new_x = (int)(2.0*k-x);
            new_y = y;
            auto iter2 = unset.find({new_x,new_y});
            if (iter2 == unset.end()) {
                return false;
            }
            unset.erase(iter);
            unset.erase({new_x,new_y});
        }
        return true;
    }
};