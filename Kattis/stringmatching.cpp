// https://open.kattis.com/problems/stringmatching

#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<int> KMP(T const& String, T const& Pattern) {
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
    while (sp < String.size()) {
        while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != String[sp])) kp = b[kp];
        kp++; sp++;
        if (kp == Pattern.size()) matches.emplace_back(sp - Pattern.size());
    }
    return matches;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern, text;
    bool firstItem;
    while (true) {
        if (!getline(cin, pattern)) break;
        if (!getline(cin, text)) break;
        auto positions = KMP(text, pattern);
        if (!positions.empty()) {
            firstItem = true;
            for (const auto &i : positions) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << ' ';
                }
                cout << i;
            }
        }
        cout << '\n';
    }
    return 0;
}