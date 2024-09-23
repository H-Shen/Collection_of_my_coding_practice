#include <bits/stdc++.h>


using namespace std;

const int MAXN = 20;
char s[MAXN], s2[MAXN];

struct Node {
    int val;
    string currentAddress;
    string nextAddress;
};

bool cmp(const Node &a, const Node &b) {
    return (a.val < b.val);
}

int main() {
    int n;
    string currentAddress;

    scanf("%d %s", &n, s);

    if (n == 0) {
        return 0;
    }

    currentAddress = s;
    int i;
    unordered_map<string, Node> save;
    Node tmp;

    for (i = 0; i < n; ++i) {
        scanf("%s %d %s", s, &tmp.val, s2);
        tmp.currentAddress = s;
        tmp.nextAddress = s2;
        save[tmp.currentAddress] = tmp;
    }

    vector<Node> A(n);
    int cnt = 0;
    while (true) {
        if (currentAddress == "-1") {
            break;
        }
        A[cnt] = save[currentAddress];
        currentAddress = save[currentAddress].nextAddress;
        ++cnt;
    }

    if (cnt == 0) {
        printf("0 -1\n");
        return 0;
    }

    A.resize(cnt);
    sort(A.begin(), A.end(), cmp);
    for (i = 0; i < cnt - 1; ++i) {
        A[i].nextAddress = A[i + 1].currentAddress;
    }
    A[cnt - 1].nextAddress = "-1";

    printf("%d %s\n", cnt, A[0].currentAddress.c_str());
    for (i = 0; i < cnt; ++i) {
        printf("%s %d %s\n", A[i].currentAddress.c_str(), A[i].val, A[i].nextAddress.c_str());
    }

    return 0;
}