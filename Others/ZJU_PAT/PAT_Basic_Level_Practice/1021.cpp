#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
char N[maxn];

bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
    return (a.first < b.first);
}

int main() {
    scanf("%s", N);
    string s = N;
    unordered_map<char, int> A;
    for (auto ch : s) {
        ++A[ch];
    }
    int len = A.size();
    vector<pair<char, int> > List(len);
    int i = 0;
    for (auto it = A.begin(); it != A.end(); ++it) {
        pair<char, int> tmp;
        tmp.first = it->first;
        tmp.second = it->second;
        List[i] = tmp;
        ++i;
    }
    sort(List.begin(), List.end(), cmp);
    for (i = 0; i < len; ++i) {
        printf("%c:%d\n", List[i].first, List[i].second);
    }
    return 0;
}