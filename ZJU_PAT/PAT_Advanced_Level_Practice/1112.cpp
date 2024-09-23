#include <bits/stdc++.h>


using namespace std;
constexpr int MAXN = 1005;

struct key {
    int firstAppearIdx = -1;
    vector<string> substring;
};

unordered_map<char, key> outputSubstring(const string &a) {
    unordered_map<char, key> A;
    string tmp;
    char lastChar = '\0';
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (lastChar == '\0') {
            lastChar = a[i];
            tmp += lastChar;
        } else if (lastChar == a[i]) {
            tmp += lastChar;
        } else {
            A[tmp[0]].substring.push_back(tmp);
            if (A[tmp[0]].firstAppearIdx == -1) {
                A[tmp[0]].firstAppearIdx = i;
            }
            tmp = a[i];
            lastChar = a[i];
        }
        if (i == static_cast<int>(a.size()) - 1) {
            A[tmp[0]].substring.push_back(tmp);

            if (A[tmp[0]].firstAppearIdx == -1) {
                A[tmp[0]].firstAppearIdx = i;
            }
        }
    }
    return A;
}

vector<pair<char, int> > sieveStuckedKeys(const unordered_map<char, key> &A, const int &k) {
    vector<pair<char, int> > res;
    bool haveAns = true;
    for (auto it = A.cbegin(); it != A.cend(); ++it) {
        haveAns = true;
        for (const auto &m : it->second.substring) {
            if (static_cast<int>(m.size()) % k != 0) {
                haveAns = false;
                break;
            }
        }
        if (haveAns) {
            res.push_back(make_pair(it->first, it->second.firstAppearIdx));
        }
    }
    return res;
}

int main() {
    int k;
    char str[MAXN];
    scanf("%d %s", &k, str);
    string s = str;
    vector<pair<char, int> > res = sieveStuckedKeys(outputSubstring(s), k);
    sort(res.begin(), res.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
        return (a.second < b.second);
    });

    for (const auto &p : res) printf("%c", p.first);
    printf("\n");

    unordered_set<char> repeatedChar;
    for (const auto &p : res) repeatedChar.insert(p.first);

    //sieve
    string ans;
    for (int i = 0; i < static_cast<int>(s.size());) {
        ans += s[i];
        if (repeatedChar.find(s[i]) != repeatedChar.end()) {
            i += k;
        } else {
            ++i;
        }
    }
    //output
    printf("%s\n", ans.c_str());

    return 0;
}