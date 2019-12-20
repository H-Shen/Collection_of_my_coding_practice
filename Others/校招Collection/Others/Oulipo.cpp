// https://ac.nowcoder.com/acm/contest/954/A
// KMP Template

#include <bits/stdc++.h>

using namespace std;

template<class T>
int KMP(T const& S, T const& K) {
    vector<int> b(K.size() + 1, -1);
    int matches{0};
    // Preprocess
    for (size_t i = 1; i <= K.size(); i++) {
        int pos = b[i - 1];
        while (pos != -1 && K[pos] != K[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }
    // Search
    int sp = 0, kp = 0;
    while (sp < S.size()) {
        while (kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = b[kp];
        kp++; sp++;
        if (kp == K.size()) ++matches;
    }
    return matches;
}

const int MAXN = 1000005;
char A[MAXN];
char B[MAXN];

int main() {
    scanf("%s", A);
    scanf("%s", B);
    printf("%d\n", KMP(string(A), string(B)));
}