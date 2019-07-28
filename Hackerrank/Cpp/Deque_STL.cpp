#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 10005;
int arr[MAXN];

void printKMax(int arr[], int n, int k) {
    deque<int> A(static_cast<unsigned long>(k));
    int i;
    for (i = 0; i < k; ++i) {   //HANDLE THE FIRST K ELEMENTS AND SAVE THE MAX ONE TO THE DEQUE
        while ((!A.empty()) && arr[i] >= arr[A.back()]) {
            A.pop_back();
        }
        A.emplace_back(i);
    }

    for (; i < n; ++i) {
        printf("%d ", arr[A.front()]);

        while ((!A.empty()) && A.front() <= i - k) {
            A.pop_front();
        }

        while ((!A.empty()) && arr[i] > arr[A.back()]) {
            A.pop_back();
        }
        A.emplace_back(i);
    }
    printf("%d\n", arr[A.front()]);
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printKMax(arr, n, k);
    }
    return 0;
}
