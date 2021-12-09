class Solution {
public:
    int f(const string &s) {
        int a, b;
        sscanf(s.c_str(), "%d:%d", &a,&b);
        return a*60+b;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = (int)keyName.size();
        unordered_map<string, vector<int>> unmap;
        for (int i = 0; i < n; ++i) {
            unmap[keyName[i]].emplace_back(f(keyTime[i]));
        }
        vector<string> ans;
        for (auto&[k,v] : unmap) {
            sort(v.begin(),v.end());
            int length = (int)v.size();
            if (length >= 3) {
                for (int i = 0; i < length; ++i) {
                    auto iter = upper_bound(v.begin(),v.end(),v[i]+60);
                    --iter;
                    int j = iter-v.begin();
                    if (j-i+1>=3) {
                        ans.emplace_back(k);
                        break;
                    } 
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};