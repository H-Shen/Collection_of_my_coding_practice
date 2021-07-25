class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = (int)num.size();
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            if (num[i] - '0' <= change[num[i] - '0']) {
                vec.emplace_back(i);
            }
        }
        if (vec.empty()) {
            return num;
        }
        int start = -1;
        int end = -1;
        vector<pair<int,int> > v;
        for (const auto &i : vec) {
            if (start == -1) {
                start = end = i;
                continue;
            }
            if (i == end+1) {
                ++end;
            }
            else {
                v.emplace_back(start,end);
                start = i;
                end = i;
            }
        }
        v.emplace_back(start,end);
        for (const auto &[i,j] : v) {
            for (int k = i; k <= j; ++k) {
                if (num[k] - '0' < change[num[k] - '0']) {
                    for (int k_ = i; k_ <= j; ++k_) {
                        num[k_] = change[num[k_] - '0'] + '0';
                    }
                    return num;
                }
            }
        }
        
        return num;
    }
};