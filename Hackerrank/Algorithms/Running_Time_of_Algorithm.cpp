#include <vector>
#include <cstdio>

using namespace std;

int swapInsertSort = 0;

void insertionSort(vector<int> &arr, int n) {

    if (n <= 1)
        return;

    int i, j;
    int temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
            swapInsertSort++;
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
    printf("%d\n", swapInsertSort);
    return 0;
}
