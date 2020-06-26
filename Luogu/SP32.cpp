#include <vector>
#include <iostream>
#include <string>

using namespace std;

template<class T>
vector<int> kmp(T const &Text, T const &Pattern) {

    vector<int> b(Pattern.size() + 1, -1);
    vector<int> matches;

    // Preprocess
    for (size_t i = 1; i <= Pattern.size(); i++) {
        int pos = b[i - 1];
        while (pos != -1 && Pattern[pos] != Pattern[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }

    // Search
    int sp = 0, kp = 0;
    while (sp < Text.size()) {
        while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != Text[sp])) {
            kp = b[kp];
        }
        ++kp;
        ++sp;
        if (kp == Pattern.size()) {
            matches.emplace_back(sp - Pattern.size());
        }
    }
    return matches;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    string needle, haystack;
    vector<int> p;
    bool first_case = true;
    while (cin >> n >> needle >> haystack) {
        p = kmp<string>(haystack, needle);
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        for (const auto &i : p) {
            cout << i << '\n';
        }
    }


    return 0;
}