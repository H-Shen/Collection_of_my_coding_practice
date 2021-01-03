class Solution {
public:
    int myAtoi(string s) {
        string s_;
        auto iter = s.begin();
        while (iter != s.end() && *iter == ' ') {
            ++iter;
        }
        while (iter != s.end() && !isdigit(*iter)) {
            s_.push_back(*iter);
            ++iter;
        }
        while (iter != s.end() && isdigit(*iter)) {
            s_.push_back(*iter);
            ++iter;
        }
        try {
            return stoi(s_);
        } catch (std::out_of_range &ex) {
            if (s_.front() == '-') {
                return numeric_limits<int>::min();
            }
            return numeric_limits<int>::max();
        } catch (...) {}
        return 0;
    }
};