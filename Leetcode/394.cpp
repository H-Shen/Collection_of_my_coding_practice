class Solution {
public:
    string convert(const string &s) {
        string repeat, content, result;
        auto iter = s.cbegin();
        while (*iter != '[') {
            repeat += *iter;
            ++iter;
        }
        ++iter;
        while (*iter != ']') {
            content += *iter;
            ++iter;
        }
        int repeat_ = stoi(repeat);
        for (int i = 0; i < repeat_; ++i) {
            result += content;
        }
        return result;
    }
    string decodeString(string s) {
        static const regex r("[0-9]+\\[[a-z]+\\]");
        string a, b, c;
        while (true) {
            smatch m;
            regex_search(s, m, r);
            if (m.empty()) {
                break;
            }
            a = s.substr(0, m.position(0));
            b = m[0].str();
            c = s.substr(m.position(0) + b.size());
            s.clear();
            s.append(a).append(convert(b)).append(c);
        }
        return s;
    }
};