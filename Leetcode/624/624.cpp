class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = (int)arrays.size();
        vector<pair<int,int>> vec(n);
        multiset<int> ms;
        for (int i = 0; i < n; ++i) {
            vec[i].first = arrays[i].front();
            vec[i].second = arrays[i].back();
            ms.insert(vec[i].first);
            ms.insert(vec[i].second);
        }
        int maxDist = numeric_limits<int>::min();
        multiset<int>::iterator iter,iter2;
        for (int i = 0; i < n; ++i) {
            
            iter = ms.find(vec[i].first);
            ms.erase(iter);
            iter2 = ms.find(vec[i].second);
            ms.erase(iter2);
            
            maxDist = max({maxDist, abs(vec[i].first - (*ms.begin())), abs(vec[i].first - *(--ms.end()))});
            ms.insert(vec[i].first);
            ms.insert(vec[i].second);
            
            iter = ms.find(vec[i].first);
            ms.erase(iter);
            iter2 = ms.find(vec[i].second);
            ms.erase(iter2);

            maxDist = max({maxDist, abs(vec[i].second - (*ms.begin())), abs(vec[i].second - *(--ms.end()))});
            ms.insert(vec[i].first);
            ms.insert(vec[i].second);
        }
        return maxDist;
    }
};