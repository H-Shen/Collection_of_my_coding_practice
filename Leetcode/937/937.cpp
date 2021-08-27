class Solution {
public:
    bool isDigitLog(const string &s) {
        bool firstEmptySpace = false;
        for (const char &ch : s) {
            if (isalpha(ch) && firstEmptySpace) {
                return false;
            }
            if (ch == ' ' && !firstEmptySpace) {
                firstEmptySpace = true;
            }
        }
        return true;
    }
    pair<string, string> parse(const string &s) {
        auto pos = s.find(' ');
        if (pos == string::npos) {
            return {s, string()};
        }
        return {s.substr(0, pos), s.substr(pos + 1)};
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;
        for (const auto &i : logs) {
            if (isDigitLog(i)) {
                digitLogs.emplace_back(i);
            } else {
                letterLogs.emplace_back(i);
            }
        }
        vector<pair<string, string> > letterLogsPair;
        for (const auto &i : letterLogs) {
            letterLogsPair.emplace_back(parse(i));
        }
        sort(letterLogsPair.begin(), letterLogsPair.end(), [](const pair<string, string> &l, const pair<string, string> &r){
            if (l.second == r.second) return l.first < r.first;
            return l.second < r.second;
        });
        for (size_t i = 0; i != letterLogs.size(); ++i) {
            if (letterLogsPair.at(i).second.empty()) {
                letterLogs.at(i) = letterLogsPair.at(i).first;
            } else {
                letterLogs.at(i) = letterLogsPair.at(i).first + ' ' + letterLogsPair.at(i).second;
            }
        }
        auto iter = logs.begin();
        for (size_t i = 0; i != letterLogs.size(); ++i) {
            *iter = letterLogs.at(i);
            ++iter;
        }
        for (size_t i = 0; i != digitLogs.size(); ++i) {
            *iter = digitLogs.at(i);
            ++iter;
        }
        return logs;
    }
};