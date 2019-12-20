// https://ac.nowcoder.com/acm/problem/15118

#include <bits/stdc++.h>

using namespace std;

vector <int> A;
vector <int> B;
vector <int> C;

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        vector <int>().swap(A);
        vector <int>().swap(B);
        vector <int>().swap(C);
        A.resize(n);
        B.resize(m);
        C.resize(n + m);
        for (auto &p : A) {
            scanf("%d", &p);
        }
        for (auto &p : B) {
            scanf("%d", &p);
        }
        auto it = set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin());
        C.resize(distance(C.begin(), it));

        if (C.empty()) {
            printf("empty\n");
        } else {
            int len = C.size();
            for (int i = 0; i < len - 1; ++i) {
                printf("%d ", C[i]);
            }
            printf("%d\n", C[len - 1]);
        }
    }
    return 0;
}
