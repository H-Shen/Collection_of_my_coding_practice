// https://www.nowcoder.com/practice/01cb04dc53f54625834f2a86c519dce9

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000;

int main() {

    int x, y, price, i;
    vector<int> priceList(MAXN);
    int len = 0;

    // INPUT
    while (~scanf("%d %d %d", &x, &y, &price)) {
        len = max(len, y);
        for (i = x - 1; i <= y - 1; ++i) {
            priceList[i] = price;
        }
    }

    // OUTPUT AND FILTER 0s
    int minVal = 0, maxVal = 0;
    if (len == 1) {
        printf("[%d, %d, %d]\n", minVal + 1, maxVal + 1, priceList[0]);
    } else {
        int currentVal = priceList[0];
        for (i = 1; i < len; ++i) {
            if (priceList[i] == currentVal) {
                ++maxVal;
                if (i == len - 1 && currentVal != 0) {
                    printf("[%d, %d, %d]\n", minVal + 1, maxVal + 1, currentVal);
                }
            } else {
                if (currentVal != 0) {
                    printf("[%d, %d, %d]", minVal + 1, maxVal + 1, currentVal);
                    if (i == len - 1) {
                        printf("\n");
                    } else {
                        printf(",");
                    }
                }
                currentVal = priceList[i];
                minVal = i;
                maxVal = i;
            }
        }
    }
    return 0;
}