// https://www.nowcoder.com/practice/a376cfc811db43719768b1a79ec3829a

// KMP Template

#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<int> KMP(T const& S, T const& K) {
    vector<int> b(K.size() + 1, -1);
    vector<int> matches;
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
        if (kp == K.size()) matches.emplace_back(sp - K.size());
    }
    return matches;
}

const int MAXN = 500005;
char A[MAXN];
char B[MAXN];

int main() {
    scanf("%s", A);
    scanf("%s", B);
    auto res = KMP(string(A), string(B));
    if (res.empty()) {
        printf("-1");
    } else {
        bool firstItem = true;
        for (const int &i : res) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}