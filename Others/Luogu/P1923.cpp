#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int *arr;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    nth_element(arr, arr + k, arr + n);
    printf("%d\n", arr[k]);

    return 0;
}