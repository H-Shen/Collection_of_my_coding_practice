class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int n = (int)encoded1.size();
        deque<pair<int,int>> e1;
        for (int i = 0; i < n; ++i) {
            e1.push_back({encoded1[i][0],encoded1[i][1]});
        }
        int m = (int)encoded2.size();
        deque<pair<int,int>> e2;
        for (int i = 0; i < m; ++i) {
            e2.push_back({encoded2[i][0],encoded2[i][1]});
        }
        vector<pair<int,int>> ans;
        int i = 0, j = 0;
        while (!e1.empty() || !e2.empty()) {
            if (e1.front().second == e2.front().second) {
                ans.emplace_back(e1.front().first * e2.front().first,e1.front().second);
                e1.pop_front();
                e2.pop_front();
            }
            else if (e1.front().second > e2.front().second) {
                ans.emplace_back(e1.front().first * e2.front().first,e2.front().second);
                e1.front().second -= e2.front().second;
                e2.pop_front();
            }
            else {
                ans.emplace_back(e1.front().first * e2.front().first,e1.front().second);
                e2.front().second -= e1.front().second;
                e1.pop_front();
            }
            while (ans.size() > 1 && ans[ans.size()-2].first == ans[ans.size()-1].first) {
                ans[ans.size()-2].second += ans[ans.size()-1].second;
                ans.pop_back();
            }
        }
        while (!e1.empty()) {
            ans.emplace_back(e1.front().first,e1.front().second);
            e1.pop_front();
            while (ans.size() > 1 && ans[ans.size()-2].first == ans[ans.size()-1].first) {
                ans[ans.size()-2].second += ans[ans.size()-1].second;
                ans.pop_back();
            }
        }
        while (!e2.empty()) {
            ans.emplace_back(e2.front().first,e2.front().second);
            e2.pop_front();
            while (ans.size() > 1 && ans[ans.size()-2].first == ans[ans.size()-1].first) {
                ans[ans.size()-2].second += ans[ans.size()-1].second;
                ans.pop_back();
            }
        }
        vector<vector<int>> res;
        for (auto&i : ans) {
            res.emplace_back(vector<int>{i.first,i.second});
        }
        return res;
    }
};