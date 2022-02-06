class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        int n = (int)s.size();
        int minVal = numeric_limits<int>::max();
        do {
            for (int i = 0; i < n-1; ++i) {
                minVal = min(minVal, stoi(s.substr(0,i+1)) + stoi(s.substr(i+1)));
            }
        } while (next_permutation(s.begin(),s.end()));
        return minVal;
    }
};