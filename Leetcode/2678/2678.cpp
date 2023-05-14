class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        string age_str;
        int age;
        for (auto&i : details) {
            age_str.clear();
            age_str.push_back(i[11]);
            age_str.push_back(i[12]);
            age = stoi(age_str);
            if (age > 60) ++cnt;
        }
        return cnt;
    }
};