class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = (int)number.size();
        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            if (number[i] == digit) {
                string s = number;
                s.erase(i, 1);
                vec.emplace_back(s);
            }
        }
        return *max_element(vec.begin(),vec.end(),[](const string&l, const string&r){
            int a = (int)l.size();
            int b = (int)r.size();
            if (a == b) {
                for (int i = 0; i < a; ++i) {
                    if (l[i] != r[i]) {
                        return l[i] < r[i];
                    }
                }
                return false;
            }
            return a < b;
        });
    }
};