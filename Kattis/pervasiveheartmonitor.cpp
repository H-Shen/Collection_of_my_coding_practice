// https://open.kattis.com/problems/pervasiveheartmonitor
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using float128 = __float128;

inline const regex r("[0-9A-za-z\\.]+");

inline
pair<vector<string>, vector<double> > parse(const string &s) {
    pair<vector<string>, vector<double> > result;
    bool has_letter;
    string temp;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
         it != end_it; ++it) {
        has_letter = false;
        temp = it->str();
        for (const char &ch : temp) {
            if (isalpha(ch)) {
                has_letter = true;
                break;
            }
        }
        if (has_letter) {
            result.first.emplace_back(temp);
        } else {
            result.second.emplace_back(stod(temp));
        }
    }
    return result;
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

    string s;
    while (getline(cin, s)) {
        auto p = parse(s);
        float128 sum = 0.0;
        for (const auto &i : p.second) {
            sum += i;
        }
        float128 avg = sum / static_cast<int>(p.second.size());
        printf("%.6lf %s\n", static_cast<double>(avg),
               join(p.first, " ").c_str());
    }

    return 0;
}
