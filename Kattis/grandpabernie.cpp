// https://open.kattis.com/problems/grandpabernie
//
#include<bits/stdc++.h>

using namespace std;
constexpr int maxn = 30;
char country[maxn];

int main() {

    int n;
    int year;
    unordered_map<string, vector<int> > A;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d", country, &year);
        A[country].emplace_back(year);
    }
    // sort
    for (auto &[k, v] : A) {
        sort(v.begin(), v.end());
    }
    // query
    int q;
    int time;
    scanf("%d", &q);
    while (q--) {
        scanf("%s %d", country, &time);
        printf("%d\n", A[country].at(time - 1));
    }

    return 0;
}
