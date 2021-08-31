class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sta;
        for (const auto &ch : s) {
            if (sta.empty()) {
                sta.push({ch, 1});
            }
            else if (ch != sta.top().first) {
                sta.push({ch, 1});
            }
            else {
                ++sta.top().second;
                if (sta.top().second >= k) {
                    sta.top().second -= k;
                    if (sta.top().second == 0) {
                        sta.pop();
                    }
                }
            }
        }
        string str;
        while (!sta.empty()) {
            str += string(sta.top().second, sta.top().first);
            sta.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};