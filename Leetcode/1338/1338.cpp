class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (auto&i : arr) ++freq[i];
        vector<pair<int,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.second > r.second;
        });
        int half =(int)arr.size()>>1;
        int ans = 0;
        int cnt = 0;
        for (auto&[k,v] : vec) {
            if (cnt + v >= half) {
                ++ans;
                break;
            }
            else {
                ++ans;
                cnt += v;
            }
        }
        return ans;
    }
};