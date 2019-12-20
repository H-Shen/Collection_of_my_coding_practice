// https://www.nowcoder.com/practice/07b66536f3f94f88908fe598108172d5

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A, B, C;

int main() {

    int k, n, entry;
    scanf("%d %d", &k, &n);

    for (int i = 0; i < n; ++i) {
        vector<int>().swap(B);
        B.resize(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &entry);
            B[j] = entry;
        }
        // A = C
        vector<int>().swap(A);
        A.resize(C.size());
        copy(C.begin(), C.end(), A.begin());

        // C = A + B
        vector<int>().swap(C);
        C.resize(A.size() + B.size());
        merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());
    }

    nth_element(C.begin(), C.begin() + k, C.end());
    printf("%d\n", C[k - 1]);
    return 0;
}