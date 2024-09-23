#include <bits/stdc++.h>

using namespace std;
const int maxn = 10;
char s0[maxn], s1[maxn];

int main() {
    int n;
    unordered_map<string, string> A;
    string str0, str1;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", s0, s1);
        str0 = s0;
        str1 = s1;
        A[str0] = str1;
    }
    int m, i;
    scanf("%d", &m);
    unordered_set<string> queryList;
    for (i = 0; i < m; ++i) {
        scanf("%s", s0);
        str0 = s0;
        queryList.insert(str0);
    }

    for (auto it = A.begin(); it != A.end(); ++it) {
        if (queryList.find(it->first) != queryList.end() &&
            queryList.find(it->second) != queryList.end()) {
            queryList.erase(it->first);
            queryList.erase(it->second);
        }
    }

    vector<string> res(queryList.begin(), queryList.end());

    sort(res.begin(), res.end());
    int len = static_cast<int>(res.size());

    printf("%d\n", len);
    if (len > 0) {
        for (i = 0; i < len - 1; ++i) {
            printf("%s ", res[i].c_str());
        }
        printf("%s\n", res.back().c_str());
    }
    return 0;
}