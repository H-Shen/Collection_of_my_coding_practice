class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> vec;
        vec.emplace_back(num);
        int n = (int)s.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                swap(s[i],s[j]);
                vec.emplace_back(stoi(s));
                swap(s[i],s[j]);
            }
        }
        return *max_element(vec.begin(),vec.end());
    }
};