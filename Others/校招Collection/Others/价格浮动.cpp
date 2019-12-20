// https://www.nowcoder.com/practice/61b883253bc54f2f8ee4b51ad9b16eee

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int N = 24;

bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
    if (A.first == B.first) {
        return (A.second < B.second);
    }
    return (A.first > B.first);
}

int main() {
    int i, tmp;
    while (true) {
        vector<pair<int, int> > A(N);

        for (i = 0; i < N; ++i) {
            if (scanf("%d", &tmp) == EOF) {
                return 0;
            }
            A[i] = make_pair(abs(tmp), i);
        }
        sort(A.begin(), A.end(), cmp);

        for (i = 0; i < N - 1; ++i) {
            printf("%d ", A[i].second);
        }
        printf("%d\n", A[N - 1].second);
    }
}