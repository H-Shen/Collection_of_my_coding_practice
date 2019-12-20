#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105, GAP = '0';
char s0[MAXN], s1[MAXN];

int main() {
    string A, B, C;
    scanf("%s %s", s0, s1);
    A = s0;
    B = s1;

    string::size_type maxLen = max(A.size(), B.size());

    A = string(maxLen - A.size(), '0') + A;
    B = string(maxLen - B.size(), '0') + B;
    C = string(maxLen, '0');
    int i;

    if (!C.empty()) {
        int add;
        for (i = static_cast<int>(C.size()) - 1; i >= 0; i -= 2) {

            add = (A[i] - GAP + B[i] - GAP) % 13;
            if (add == 10) {
                C[i] = 'J';
            } else if (add == 11) {
                C[i] = 'Q';
            } else if (add == 12) {
                C[i] = 'K';
            } else {
                C[i] = static_cast<char>(add + GAP);
            }
        }
    }

    if (C.size() >= 2) {
        int sub;
        for (i = (int) C.size() - 2; i >= 0; i -= 2) {
            sub = B[i] - A[i];
            if (sub < 0) {
                sub += 10;
            }
            C[i] = static_cast<char>(sub + GAP);
        }
    }

    printf("%s\n", C.c_str());
    return 0;
}