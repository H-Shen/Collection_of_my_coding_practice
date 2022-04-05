vector<int> getRev(string& a) {
    vector<int> aRev(a.size());
    for (int i = 0, j = (int)a.size()-1; i < (int)a.size(); ++i, --j) {
        aRev[i] = a[j] - '0';
    }
    return aRev;
}


class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> aRev = getRev(num1);
        vector<int> bRev = getRev(num2);
        int maxLength = (int)max(aRev.size(), bRev.size());
        while ((int)aRev.size() < maxLength) aRev.emplace_back(0);
        while ((int)bRev.size() < maxLength) bRev.emplace_back(0);
        vector<int> cRev(maxLength + 1);
        for (int i = 0; i < maxLength; ++i) {
            cRev[i] += aRev[i] + bRev[i];
            if (cRev[i] >= 10) {
                cRev[i] -= 10;
                ++cRev[i+1];
            }
        }
        while (cRev.size() > 1 && cRev.back() == 0) cRev.pop_back();
        string c;
        for (auto iter = cRev.rbegin(); iter != cRev.rend(); ++iter) {
            c.push_back(*iter + '0');
        }
        return c;
    }
};