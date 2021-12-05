class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        constexpr int MAXN = 10;
        int stats[MAXN]{};
        for (auto& i : digits) {
            if (stats[i] == 3) continue;
            ++stats[i];
        }
        vector<int> tempVec;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < stats[i]; ++j) {
                tempVec.emplace_back(i);
            }
        }
        unordered_set<int> ans;
        int n = (int)tempVec.size();
        string s;
        s.reserve(3);
        int temp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && i != k && j != k) {
                        if (tempVec[i] == 0 || (tempVec[i] == tempVec[j] && tempVec[j] == 0) || (tempVec[i] == tempVec[j] && tempVec[j] == tempVec[k] && tempVec[k] == 0)) {
                            continue;
                        }
                        s[0] = tempVec[i] + '0';
                        s[1] = tempVec[j] + '0';
                        s[2] = tempVec[k] + '0';
                        if (!(tempVec[k] & 1)) {
                            ans.insert(stoi(s));
                        }
                    }
                }
            }
        }
        vector<int> vec(ans.begin(),ans.end());
        sort(vec.begin(),vec.end());
        return vec;
    }
};