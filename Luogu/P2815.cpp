#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 100;
char cstr[MAXN];

inline const regex r("(:){3,}");

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

inline static
string removeHeadZeroes(const string &s) {
    if (s.size() > 1 && s.front() == '0') {
        deque<char> temp_deque(s.begin(), s.end());
        while (temp_deque.size() > 1 && temp_deque.front() == '0') {
            temp_deque.pop_front();
        }
        return string(temp_deque.begin(), temp_deque.end());
    }
    return s;
}

inline static
string join(const vector<string> &v, const string &str) {
    string s;
    for (auto p = cbegin(v); p != cend(v); ++p) {
        s.append(*p);
        if (p != cend(v) - 1) {
            s.append(str);
        }
    }
    return s;
}

int main() {
    
    scanf("%s", cstr);
    string s(cstr);
    auto p = splitByChar(s, ':');
    for (auto &i : p) {
        i = removeHeadZeroes(i);
    }
    // check sub-arrays that contain 0s only
    vector<pair<int, int> > save;
    int length = static_cast<int>(p.size());
    int start = -1;
    int end = -1;
    for (int i = 0; i < length; ++i) {
        if (p.at(i) == "0") {
            if (start == -1) {
                start = i;
                end = i;
            } else {
                end = i;
            }
        } else {
            if (start != -1) {
                save.emplace_back(make_pair(start, end));
                start = -1;
                end = -1;
            }
        }
    }
    if (start != -1) {
        save.emplace_back(make_pair(start, end));
    }
    if (save.empty()) {
        printf("%s\n", join(p, ":").c_str());
    }
    else {
        int max_dist = -1;
        for (const auto &[start_, end_] : save) {
            max_dist = max(max_dist, end_ - start_ + 1);
        }
        int start_pos{};
        int end_pos{};
        for (const auto &[start_, end_] : save) {
            if (end_ - start_ + 1 == max_dist) {
                start_pos = start_;
                end_pos = end_;
                break;
            }
        }
        for (int i = start_pos; i <= end_pos; ++i) {
            p.at(i) = "";
        }
        string result = join(p, ":");
        string output;
        regex_replace(back_inserter(output), result.begin(), result.end(), r, "::");
        printf("%s\n", output.c_str());
    }

    return 0;
}