// https://ac.nowcoder.com/acm/problem/17386

#include <vector>
#include <cstdio>

using namespace std;

vector < vector <int> > A, B, C;

int main()
{
    int t, n, m, p, q;
    scanf("%d", &t);

    for (int kase = 1; kase <= t; ++kase) {

        //initialization
        vector < vector <int> >().swap(A);
        vector < vector <int> >().swap(B);
        vector < vector <int> >().swap(C);

        scanf("%d %d %d %d", &m, &n, &p, &q);

        A.resize(m);
        for (auto &&i : A) {
            i.resize(n);
        }
        B.resize(p);
        for (auto &&i : B) {
            i.resize(q);
        }

        //input
        for (auto &&i : A) {
            for (auto &&j : i) {
                scanf("%d", &j);
            }
        }
        for (auto &&i : B) {
            for (auto &&j : i) {
                scanf("%d", &j);
            }
        }

        //output
        printf("Case %d:\n", kase);
        if (n != p) {
            printf("ERROR\n");
        }
        else {

            C.resize(m);
            for (auto &&i : C) {
                i.resize(q);
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < q; ++j) {
                    for (int k = 0; k < n; ++k) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < q - 1; ++j) {
                    printf("%d ", C[i][j]);
                }
                printf("%d\n", C[i][q - 1]);
            }
        }
    }
    return 0;
}