#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tmp, i;
    cin >> n;
    unordered_map<int, int> A;
    vector<int> a(n);

    for (i = 0; i < n; ++i) {
        cin >> tmp;
        a[i] = tmp;
        if (A.find(tmp) != A.end()) {
            ++A[tmp];
        } else {
            A[tmp] = 1;
        }
    }

    bool haveAns = false;
    for (i = 0; i < n; ++i) {
        if (A[a[i]] == 1) {
            haveAns = true;
            printf("%d\n", a[i]);
            break;
        }
    }
    if (!haveAns) {
        printf("None\n");
    }
}