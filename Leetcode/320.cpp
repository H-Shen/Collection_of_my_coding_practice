constexpr int MAXN = 15+1;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        bitset<MAXN> bs;
        vector<string> v;
        int n = (int)word.size();
        int total = 1 << n;
        int counter;
        for (int i = 0; i < total; ++i) {
            string s;
            counter = 0;
            for (int j = 0; j < n; ++j) {
                if (bs[j]) {
                    if (counter > 0) {
                        s += to_string(counter);
                        counter = 0;
                    }
                    s.push_back(word[j]);
                    
                }
                else {
                    ++counter;
                }
            }
            if (counter > 0) {
                s += to_string(counter);
            }
            v.emplace_back(s);
            bs = bitset<MAXN>(bs.to_ulong()+1);
        }
        return v;
    }
};