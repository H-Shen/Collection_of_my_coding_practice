#include <bits/stdc++.h>

using namespace std;
const int MAXN = 20;
char s[MAXN];

struct User {
    string id;
    int signIn = 0;
    int signOut = 0;
};

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    if (N == 0) return 0;

    vector<User> A(N);

    int i;
    User tmp;
    int h0, m0, s0, h1, m1, s1;

    for (i = 0; i < N; ++i) {
        scanf("%s %d:%d:%d %d:%d:%d", s, &h0, &m0, &s0, &h1, &m1, &s1);
        tmp.id = s;
        tmp.signIn = h0 * 3600 + m0 * 60 + s0;
        tmp.signOut = h1 * 3600 + m1 * 60 + s1;
        A[i] = tmp;
    }

    auto f0 = [](const User &a, const User &b) -> bool { return a.signIn < b.signIn; };
    auto f1 = [](const User &a, const User &b) -> bool { return a.signOut < b.signOut; };

    printf("%s ", (*min_element(A.begin(), A.end(), f0)).id.c_str());
    printf("%s\n", (*max_element(A.begin(), A.end(), f1)).id.c_str());

}