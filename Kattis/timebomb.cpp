// https://open.kattis.com/problems/timebomb
//
#include <bits/stdc++.h>

using namespace std;

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

template<typename T>
inline static
vector<vector<T> > matrixRotation(const vector<vector<T> > &A) {
    // Case 1:
    if (A.empty() || A.front().empty()) {
        return vector<vector<T> >();
    }
    // Case 2:
    vector<vector<T> > result(A.front().size(), vector<T>(A.size()));
    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result.at(i).size(); ++j) {
            result.at(i).at(j) = A.at(j).at(i);
        }
    }
    return result;
}

unordered_map<string, int> ascii2number;
unordered_map<int, string> number2ascii;

inline static
void pre() {
    string s = "***   * *** *** * * *** *** *** *** ***\n"
               "* *   *   *   * * * *   *     * * * * *\n"
               "* *   * *** *** *** *** ***   * *** ***\n"
               "* *   * *     *   *   * * *   * * *   *\n"
               "***   * *** ***   * *** ***   * *** ***";
    auto temp_string = splitByChar(s, '\n');
    vector<vector<char> > temp_vec;
    for (const auto &i : temp_string) {
        temp_vec.emplace_back(i.begin(), i.end());
    }
    temp_vec = matrixRotation(temp_vec);
    int counter = 0;
    string content;
    int index = 0;
    for (const auto &i : temp_vec) {
        ++counter;
        if (counter > 3) {
            counter = 0;
            ascii2number[content] = index;
            number2ascii[index] = content;
            ++index;
            content = "";
            continue;
        }
        content += string(i.begin(), i.end());
        if (counter != 3) {
            content.push_back('\n');
        }
    }
    if (!content.empty()) {
        ascii2number[content] = 9;
        number2ascii[index] = content;
    }
}

inline static
bool parse(string &number) {
    vector<vector<char> > temp_vec;
    string s;
    while (getline(cin, s)) {
        temp_vec.emplace_back(s.begin(), s.end());
    }
    temp_vec = matrixRotation(temp_vec);
    // 4x - 1: x : count of digits
    int n = static_cast<int>(temp_vec.size());
    if ((n + 1) % 4 != 0) {
        return false;
    }
    int counter = 0;
    string content;
    for (const auto &i : temp_vec) {
        ++counter;
        if (counter > 3) {
            counter = 0;
            if (ascii2number.find(content) == ascii2number.end()) {
                return false;
            } else {
                number += to_string(ascii2number[content]);
            }
            content = "";
            continue;
        }
        content += string(i.begin(), i.end());
        if (counter != 3) {
            content.push_back('\n');
        }
    }
    if (!content.empty()) {
        if (ascii2number.find(content) == ascii2number.end()) {
            return false;
        } else {
            number += to_string(ascii2number[content]);
        }
    }
    return true;
}

inline static
bool isDivisibleBySix(const string &s) {
    unordered_set<char> even_set = {'0', '2', '4', '6', '8'};
    if (even_set.find(s.back()) == even_set.end()) {
        return false;
    }
    long long sum = 0;
    for (const char &ch : s) {
        sum += static_cast<long long>(ch - '0');
    }
    return (sum % 3 == 0);
}

int main() {

    pre();
    string number;
    if (parse(number)) {
        if (isDivisibleBySix(number)) {
            cout << "BEER!!\n";
        } else {
            cout << "BOOM!!\n";
        }
    } else {
        cout << "BOOM!!\n";
    }

    return 0;
}
