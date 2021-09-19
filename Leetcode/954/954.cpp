class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> ms1;
        multiset<int, greater<>> ms2;
        for (auto &i : arr) {
            if (i >= 0) {
                ms1.insert(i);
            } else {
                ms2.insert(i);
            }
        }
        if ((ms1.size() & 1) || (ms2.size() & 1)) {
            return false;
        }
        int temp;
        while (!ms1.empty()) {
            temp = *ms1.begin();
            ms1.erase(ms1.begin());
            auto iter = ms1.find(temp*2);
            if (iter == ms1.end()) {
                return false;
            }
            ms1.erase(iter);
        }
        while (!ms2.empty()) {
            temp = *ms2.begin();
            ms2.erase(ms2.begin());
            auto iter = ms2.find(temp*2);
            if (iter == ms2.end()) {
                return false;
            }
            ms2.erase(iter);
        }
        return true;
    }
};