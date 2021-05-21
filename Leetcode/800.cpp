class Solution {
public:
    int getSimilarity(const string &l, const string &r) {
        string ab, cd, ef, uv, wx, yz;
        ab.push_back(l[1]);
        ab.push_back(l[2]);
        cd.push_back(l[3]);
        cd.push_back(l[4]);
        ef.push_back(l[5]);
        ef.push_back(l[6]);
        
        uv.push_back(r[1]);
        uv.push_back(r[2]);
        wx.push_back(r[3]);
        wx.push_back(r[4]);
        yz.push_back(r[5]);
        yz.push_back(r[6]);
        
        return -(int)pow(stoi(ab,nullptr,16)-stoi(uv,nullptr,16),2)
                -(int)pow(stoi(cd,nullptr,16)-stoi(wx,nullptr,16),2)
                -(int)pow(stoi(ef,nullptr,16)-stoi(yz,nullptr,16),2);
        
    }
    string similarRGB(string color) {
        string s = "0123456789abcdef";
        string p = "#000000";
        string ans;
        int sim = numeric_limits<int>::min();
        int temp;
        for (const auto &i : s) {
            for (const auto &j : s) {
                for (const auto &k : s) {
                    p[1] = p[2] = i;
                    p[3] = p[4] = j;
                    p[5] = p[6] = k;
                    temp = getSimilarity(color, p);
                    if (temp > sim) {
                        sim = temp;
                        ans = p;
                    }
                }
            }
        }
        return ans;
    }
};