#include <cstdio>

using namespace std;
const int MAX_ELEMENT = 5;

int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    int sum = 0;
    int count = 0;
    for (; a <= b; ++a) {
        printf("%5d", a);
        sum += a;
        ++count;
        if (count == MAX_ELEMENT) {
            printf("\n");
            count = 0;
        }
    }
    if (count != 0) {
        printf("\n");
    }
    printf("Sum = %d", sum);
    return 0;
}