class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        deque<int> dq(spaces.begin(),spaces.end());
        int length = (int)s.size();
        string result;
        for (int i = 0; i < length; ++i) {
            if (!dq.empty() && i == dq.front()) {
                dq.pop_front();
                result.push_back(' ');
            }
            result.push_back(s[i]);
        }
        return result;
    }
};