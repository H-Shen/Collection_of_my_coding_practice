// https://ac.nowcoder.com/acm/problem/15521

#include <bits/stdc++.h>

using namespace std;

struct Man {
    int correctCnt = 0;
    string name;
};

int correctCounter(const string &a, const string &b) {
    int cnt = 0;
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        if (a[i] == b[i]) {
            ++cnt;
        }
    }
    return cnt;
}

bool cmp(const Man &a, const Man &b) {
    if (a.correctCnt == b.correctCnt) {
        return (a.name < b.name);
    }
    return (a.correctCnt > b.correctCnt);
}

int main() {
    int n, m;
    string ans, tmpAns;
    cin >> n >> m >> ans;
    vector<Man> A(m);
    for (auto &&p : A) {
        cin >> p.name >> tmpAns;
        p.correctCnt = correctCounter(ans, tmpAns);
    }
    sort(A.begin(), A.end(), cmp);
    printf("%s\n", A[0].name.c_str());
    printf("%.2f\n", static_cast<double>(A[0].correctCnt) / static_cast<double>(n) * 100.0);
    return 0;
}