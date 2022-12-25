class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        auto parse = [&](const string& s) {
            int result = 0;
            istringstream iss(s);
            string temp;
            vector<string> v;
            do {
                iss >> temp;
                v.emplace_back(temp);
            } while (iss);
            v.pop_back();
            for (auto&i : v) {
                if (pos.count(i) > 0) {
                    result += 3;
                }
                else if (neg.count(i) > 0) {
                    --result;
                }
            }
            return result;
        };
        int n = (int)report.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].first = student_id[i];
            vec[i].second = parse(report[i]);
        }
        sort(vec.begin(), vec.end(), [&](const auto &l, const auto &r){
            if (l.second == r.second) {
                return l.first < r.first;
            }
            return l.second > r.second;
        });
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = vec[i].first;
        }
        return ans;
    }
};