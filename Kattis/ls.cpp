// https://open.kattis.com/problems/ls
//
#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 105;
char str[maxn];

bool hasPattern(const string & text, const string & pattern) {
    auto pattern_iter = pattern.cbegin();
    for (const char &ch : text) {
        if (*pattern_iter == ch) {
            ++pattern_iter;
        }
    }
    return pattern_iter == pattern.cend();
}

inline static
string filter(const string &s) {
    string ret;
    for (size_t i = 0; i != s.size(); ++i) {
        if (s.at(i) != '*') {
            ret += s.at(i);
        }
    }
    return ret;
}

int main() {

    scanf("%s", str);
    string s(str);
    string patternString;
    int pattern;
    // Pattern 0: single character
    if (s.size() == 1) {
        pattern = 0;
    }
    // Pattern 1: [ab.] ... [ab.]
    else if (s.front() != '*' && s.back() != '*') {
        pattern = 1;
        patternString = filter(s.substr(1, s.size() - 2));
    }
    // Pattern 2: [ab.] ... *
    else if (s.front() != '*' && s.back() == '*') {
        pattern = 2;
        patternString = filter(s.substr(1));
    }
    // Pattern 3: * ... [ab.]
    else if (s.front() == '*' && s.back() != '*') {
        pattern = 3;
        patternString = filter(s.substr(0, s.size() - 1));
    }
    // Pattern 4: * ... *
    else {
        pattern = 4;
        patternString = filter(s);
    }

    int n;
    string input;
    string temp;
    bool hasAns;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        input = str;
        hasAns = false;
        switch (pattern) {
            // Pattern 0: single character
            case 0:
                if (s == "*") {
                    if (!input.empty()) {
                        hasAns = true;
                    }
                } else {
                    if (input.find(s.front()) != string::npos) {
                        hasAns = true;
                    }
                }
                break;
            // Pattern 1: [ab.] ... [ab.]
            case 1:
                if (input.front() == s.front()) {
                    if (input.back() == s.back()) {
                        temp = filter(input.substr(1, input.size() - 2));
                        if (hasPattern(temp, patternString)) {
                            hasAns = true;
                        }
                    }
                }
                break;
            // Pattern 2: [ab.] ... *
            case 2:
                if (input.front() == s.front()) {
                    temp = filter(input.substr(1));
                    if (hasPattern(temp, patternString)) {
                        hasAns = true;
                    }
                }
                break;
            // Pattern 3: * ... [ab.]
            case 3:
                if (input.back() == s.back()) {
                    temp = filter(input.substr(0, input.size() - 1));
                    //cout << temp << endl;
                    if (hasPattern(temp, patternString)) {
                        hasAns = true;
                    }
                }
                break;
            // Pattern 4: * ... *
            default:
                temp = filter(input);
                if (hasPattern(temp, patternString)) {
                    hasAns = true;
                }
                break;
        }
        if (hasAns) {
            printf("%s\n", input.c_str());
        }
    }
    return 0;
}
