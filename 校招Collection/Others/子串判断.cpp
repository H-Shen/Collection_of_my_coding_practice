// https://www.nowcoder.com/practice/917a800d4de1423394827932f4725c68

class Substr {
public:
    vector<bool> chkSubStr(vector <string> p, int n, string s) {
        // write code here
        vector<bool> result(p.size());
        for (int i = 0; i < n; ++i) {
            if (s.find(p.at(i)) != string::npos) {
                result.at(i) = true;
            }
        }
        return result;
    }
};