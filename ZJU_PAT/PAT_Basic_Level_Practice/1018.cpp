#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
char s[maxn];

struct Player {
    int w = 0;
    int t = 0;
    int l = 0;
    unordered_map<char, int> winLog;
};

bool cmp(const pair<char, int> &a, const pair<char, int> b) {
    if (a.second == b.second) {
        return (a.first < b.first);
    }
    return (a.second > b.second);
}

int main() {
    int n;
    Player A, B;
    A.winLog['C'] = 0;
    A.winLog['B'] = 0;
    A.winLog['J'] = 0;
    B.winLog['C'] = 0;
    B.winLog['B'] = 0;
    B.winLog['J'] = 0;

    char a, b;
    scanf("%d", &n);
    getchar();

    while (n--) {

        scanf("%c %c", &a, &b);
        getchar();

        if (a == b) {
            ++A.t;
            ++B.t;
        } else if (a == 'C' && b == 'J') {
            ++A.w;
            ++A.winLog[a];
            ++B.l;
        } else if (a == 'J' && b == 'B') {
            ++A.w;
            ++A.winLog[a];
            ++B.l;
        } else if (a == 'B' && b == 'C') {
            ++A.w;
            ++A.winLog[a];
            ++B.l;
        } else if (a == 'C' && b == 'B') {
            ++B.w;
            ++B.winLog[b];
            ++A.l;
        } else if (a == 'J' && b == 'C') {
            ++B.w;
            ++B.winLog[b];
            ++A.l;
        } else if (a == 'B' && b == 'J') {
            ++B.w;
            ++B.winLog[b];
            ++A.l;
        }
    }

    printf("%d %d %d\n", A.w, A.t, A.l);
    printf("%d %d %d\n", B.w, B.t, B.l);

    vector<pair<char, int> > winLogA;
    for (auto it = A.winLog.cbegin(); it != A.winLog.cend(); ++it) {
        pair<char, int> tmp;
        tmp.first = it->first;
        tmp.second = it->second;
        winLogA.push_back(tmp);
    }
    sort(winLogA.begin(), winLogA.end(), cmp);

    vector<pair<char, int> > winLogB;
    for (auto it = B.winLog.cbegin(); it != B.winLog.cend(); ++it) {
        pair<char, int> tmp;
        tmp.first = it->first;
        tmp.second = it->second;
        winLogB.push_back(tmp);
    }
    sort(winLogB.begin(), winLogB.end(), cmp);
    printf("%c %c\n", winLogA[0].first, winLogB[0].first);
    return 0;
}