#include <bits/stdc++.h>

using namespace std;
using pairType = unordered_map<string, int>::value_type;

bool cmp(const pairType &p1, const pairType &p2) {
    if (p1.second == p2.second) {
        return (p1.first < p2.first);
    }
    return (p1.second < p2.second);
}

int main() {
    unordered_map<string, int> A;
    string s;
    getline(cin, s);
    int i;
    int len = s.size();
    string cnt;
    vector<string> a;
    bool inWord = false;

    for (i = 0; i < len; ++i) {
        if (!inWord && !isalnum(s[i])) {
            continue;
        } else if (!inWord && isalnum(s[i])) {
            inWord = true;
            cnt += static_cast<char>(tolower(s[i]));
        } else if (inWord && isalnum(s[i])) {
            cnt += static_cast<char>(tolower(s[i]));
        } else if (inWord && !isalnum(s[i])) {
            inWord = false;
            ++A[cnt];
            cnt = "";
        }
    }

    if (!cnt.empty()) {
        ++A[cnt];
    }

    auto res = max_element(A.begin(), A.end(), cmp);
    printf("%s %d\n", (res->first).c_str(), res->second);

    return 0;
}