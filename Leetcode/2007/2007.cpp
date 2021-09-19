class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if ((int)changed.size() & 1) {
            return vector<int>();
        }
        multiset<int> ms;
        for (auto &i : changed) {
            ms.insert(i);
        }
        vector<int> ans;
        int temp;
        while (!ms.empty()) {
            ans.emplace_back(*ms.begin());
            ms.erase(ms.begin());
            temp = ans.back();
            auto iter = ms.find(temp<<1);
            if (iter == ms.end()) {
                return vector<int>();
            }
            ms.erase(iter);
        }
        return ans;
    }
};