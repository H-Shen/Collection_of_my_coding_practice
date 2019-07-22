#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void insertionSort(vector<int> &arr, int n) {

    if (n <= 1)
        return;

    int i, j;
    int temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int main(void) {

    int len, i;
    scanf("%d", &len);
    vector<int> A(len);
    for (i = 0; i < len; i++)
        scanf("%d", &A[i]);

    vector<int> A_copy = A;
    insertionSort(A_copy, len);

    for (i = 0; i < len - 1; i++)
        printf("%d ", A_copy[i]);
    printf("%d\n", A_copy[len - 1]);

    return 0;
}

