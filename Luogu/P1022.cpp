#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline const regex r("((\\+|\\-)?\\d*[a-z]+|(\\+|\\-)?\\d+)");

inline
pair<string, string> parse(const string &s) {
    pair<string, string> result;
    auto iter = s.cbegin();
    while (*iter != '=') {
        result.first.push_back(*iter);
        ++iter;
    }
    ++iter;
    while (iter != s.cend()) {
        result.second.push_back(*iter);
        ++iter;
    }
    return result;
}

inline
ll get_coeff(const string &s) {
    string coeff;
    for (const char &ch : s) {
        if (isalpha(ch)) {
            break;
        } else {
            coeff.push_back(ch);
        }
    }
    if (coeff.empty()) {
        return 1;
    } else if (coeff == "-") {
        return -1;
    }
    return stoll(coeff);
}

ll left_coeff;
ll left_const;
ll right_coeff;
ll right_const;
string variable_name;

inline
string get_variable_name(const string &s) {
    string result;
    bool encounter_alpha = false;
    for (const char &ch : s) {
        if (isalpha(ch)) {
            if (!encounter_alpha) {
                encounter_alpha = true;
            }
            result.push_back(ch);
        } else if (encounter_alpha) {
            break;
        }
    }
    return result;
}

inline
bool include_variable_name(const string &s) {
    return search(s.begin(), s.end(), variable_name.begin(),
                  variable_name.end()) != s.end();
}

int main(int argc, char *argv[]) {

    string s;
    cin >> s;
    variable_name = get_variable_name(s);
    auto p = parse(s);
    string temp;
    // parse left
    for (sregex_iterator it(p.first.begin(), p.first.end(), r), end_it;
         it != end_it; ++it) {
        temp = it->str();
        if (include_variable_name(temp)) {
            left_coeff += get_coeff(temp);
        } else {
            left_const += stoll(temp);
        }
    }
    // parse right
    for (sregex_iterator it(p.second.begin(), p.second.end(), r), end_it;
         it != end_it; ++it) {
        temp = it->str();
        if (include_variable_name(temp)) {
            right_coeff += get_coeff(temp);
        } else {
            right_const += stoll(temp);
        }
    }
    // left_coeff * variable = right_const
    right_const -= left_const;
    left_coeff -= right_coeff;
    double result;
    if (right_const == 0) {
        result = 0.0;
    } else {
        result = right_const * 1.0 / left_coeff;
    }
    printf("%s=%.3lf\n", variable_name.c_str(), result);

    return 0;
}