class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<char> odd, even;
        for (auto& ch : s) {
            if ((int)(ch - '0') % 2 == 0) {
                even.emplace_back(ch);
            }
            else {
                odd.emplace_back(ch);
            }
        }
        sort(even.begin(),even.end(),greater<>());
        sort(odd.begin(),odd.end(),greater<>());
        int i = 0, j = 0;
        string result;
        for (auto& ch : s) {
            if ((int)(ch - '0') % 2 == 0) {
                result.push_back(even[i]);
                ++i;
            }
            else {
                result.push_back(odd[j]);
                ++j;
            }
        }
        return stoi(result);
    }
};