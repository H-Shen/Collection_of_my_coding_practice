
// KMP Template adjusted from UofC_Notebook_2016

// Knuth-Morris-Pratt algorithm. Complexity: O (m + n)
// This function returns a vector containing the zero-based index of the start of each match of Pattern in Text. It works with strings,
// vectors, and pretty much any array-indexed data structure that has a size method. Matches may overlap.

#include <bits/stdc++.h>

using namespace std;

template<class T>
vector<int> kmp(T const &Text, T const &Pattern) {

    vector<int> b(Pattern.size() + 1, -1);
    vector<int> matches;

    // Preprocess
    for (size_t i = 1; i <= Pattern.size(); i++) {
        int pos = b[i - 1];
        while (pos != -1 && Pattern[pos] != Pattern[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }

    // Search
    int sp = 0, kp = 0;
    while (sp < Text.size()) {
        while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != Text[sp])) {
            kp = b[kp];
        }
        ++kp;
        ++sp;
        if (kp == Pattern.size()) {
            matches.emplace_back(sp - Pattern.size());
        }
    }
    return matches;
}

const int MAXN = 500005;
char A[MAXN];
char B[MAXN];

int main() {
    scanf("%s", A);
    scanf("%s", B);
    auto res = kmp(string(A), string(B));
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
