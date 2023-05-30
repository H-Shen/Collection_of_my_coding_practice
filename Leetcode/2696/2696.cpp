class Solution {
public:
    int minLength(string s) {
        while (true) {
            if (auto i = s.find("AB"); i != string::npos) {
                s.erase(i, 2);
                continue;
            }
            if (auto i = s.find("CD"); i != string::npos) {
                s.erase(i, 2);
                continue;
            }
            break;
        }
        return (int)s.size();
    }
};