// https://www.nowcoder.com/practice/a174820de48147d489f64103af152709

#include <cstdio>
#include <vector>

using namespace std;

int main() {

    //input
    int n, i;
    scanf("%d", &n);

    int sum = 0;
    vector<int> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        sum += A[i];
    }

    //checking the remainder
    if (sum % n != 0) {
        printf("-1\n");
    } else {

        int avg = sum / n;

        //judging the parity
        if (avg % 2 == 0) {
            for (i = 0; i < n; ++i) {
                if (A[i] % 2 != 0) {
                    printf("-1\n");
                    return 0;
                }
            }
        } else {
            for (i = 0; i < n; ++i) {
                if (A[i] % 2 == 0) {
                    printf("-1\n");
                    return 0;
                }
            }
        }

        //calculating times for allocation
        int cnt = 0;
        int rest = 0;
        vector<int> lessThanAvg;

        for (i = 0; i < n; ++i) {
            if (A[i] < avg) {
                lessThanAvg.push_back(A[i]);
            } else if (A[i] > avg) {
                rest = rest + A[i] - avg;
            }
        }

        int lessThanAvgLen = lessThanAvg.size();
        for (i = 0; i < lessThanAvgLen; ++i) {
            while (lessThanAvg[i] != avg) {
                ++cnt;
                rest -= 2;
                lessThanAvg[i] += 2;

                //not enough number to allocate
                if (rest < 0) {
                    printf("-1\n");
                    return 0;
                }
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}