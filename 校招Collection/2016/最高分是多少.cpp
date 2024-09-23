// https://www.nowcoder.com/practice/3897c2bcc87943ed98d8e0b9e18c4666

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

    int N, M, i, j, idA, idB, maxVal, tempVal;
    char temp;

    while (scanf("%d %d", &N, &M) != EOF) {
        vector<int> A(N);
        for (i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        for (i = 0; i < M; i++) {
            scanf(" %c", &temp);
            if (temp == 'Q') {
                scanf("%d %d", &idA, &idB);
                if (idA > idB)
                    swap(idA, idB);
                maxVal = *max_element(A.begin() + idA - 1, A.begin() + idB);
                printf("%d\n", maxVal);
            } else {
                scanf("%d %d", &idA, &tempVal);
                A[idA - 1] = tempVal;
            }
        }
    }
    return 0;
}