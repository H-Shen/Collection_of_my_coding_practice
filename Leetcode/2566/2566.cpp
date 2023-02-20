class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        vector<int> vec;
        string temp;
        for (char ch = '0'; ch <= '9'; ++ch) {
            for (char newch = '0'; newch <= '9'; ++newch) {
                temp = s;
                for (auto&i : temp) {
                    if (i == ch) {
                        i = newch;
                    }
                }
                vec.emplace_back(stoi(temp));
            }
        }
        auto p = minmax_element(vec.begin(),vec.end());
        return (*p.second) - (*p.first);
    }
};