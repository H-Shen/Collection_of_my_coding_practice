class Solution {
public:
    string digitSum(string s, int k) {
        if ((int)s.size() <= k) {
            return s;
        }
        vector<string> vec;
        string temp;
        for (auto& ch : s) {
            if ((int)temp.size() == k) {
                vec.emplace_back(temp);
                temp.clear();
                temp.push_back(ch);
            }
            else {
                temp.push_back(ch);
            }
        }
        if (!temp.empty()) {
            vec.emplace_back(temp);
        }
        int sum;
        for (auto& i : vec) {
            sum = 0;
            for (auto& ch : i) {
                sum += (char)(ch - '0');
            }
            i = to_string(sum);
        }
        string result;
        for (auto& i : vec) {
            result += i;
        }
        return digitSum(result, k);
    }
};