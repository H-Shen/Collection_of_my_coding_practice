// https://open.kattis.com/problems/variablearithmetic
//
#include <bits/extc++.h>

using namespace std;

inline unordered_set<string> validNumber;

inline static
vector<string> parse(const string &s) {

    istringstream iss(s);
    string temp;
    vector<string> A;
    do {
        iss >> temp;
        A.emplace_back(temp);
    } while (iss);
    A.pop_back();

    return A;
}

inline static
string join(const std::vector<string> &v, const string &str) {
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

    for (int i = 0; i <= 100; ++i) {
        validNumber.insert(to_string(i));
    }

    ios_base::sync_with_stdio(false);
    unordered_map<string, int> variable2number;
    string s;
    while (true) {
        getline(cin, s);
        if (s == "0") {
            break;
        }
        auto p = parse(s);
        // x = y
        if (p.size() == 3 && p.at(1) == "=") {
            variable2number[p.at(0)] = stoi(p.at(2));
        }
        else {
            vector<string> undefined;
            int sumOfNumber = 0;
            for (const auto &i : p) {
                if (i != "+") {
                    if (validNumber.find(i) != validNumber.end()) {
                        sumOfNumber += stoi(i);
                    } else if (variable2number.find(i) != variable2number.end()) {
                        sumOfNumber += variable2number[i];
                    } else {
                        undefined.emplace_back(i);
                    }
                }
            }
            // output
            if (undefined.empty()) {
                cout << sumOfNumber << endl;
            } else if (sumOfNumber == 0) {
                cout << join(undefined, " + ") << endl;
            } else {
                cout << sumOfNumber << " + " << join(undefined, " + ") << endl;
            }
        }
    }

    return 0;
}
