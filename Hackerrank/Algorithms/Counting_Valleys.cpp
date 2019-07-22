#include <cstdio>
#include <vector>

using namespace std;

struct Point {
    char status;
    int left, right, avg;
};

int main() {

    int n, i;
    scanf("%d", &n);
    getchar();

    Point lastPoint, crnPoint;
    lastPoint.left = 0;
    scanf("%c", &lastPoint.status);
    if (lastPoint.status == 'U') {
        lastPoint.right = lastPoint.left + 2;
    }
    else {
        lastPoint.right = lastPoint.left - 2;
    }
    lastPoint.avg = (lastPoint.left + lastPoint.right) / 2;

    int valley = 0;
    bool inAValley = false;
    if (lastPoint.status == 'D' && lastPoint.avg == -1) {
        inAValley = true;
    }

    for (i = 1; i < n; i++) {

        crnPoint.left = lastPoint.right;
        scanf("%c", &crnPoint.status);
        if (crnPoint.status == 'U') {
            crnPoint.right = crnPoint.left + 2;
        }
        else {
            crnPoint.right = crnPoint.left - 2;
        }
        crnPoint.avg = (crnPoint.left + crnPoint.right) / 2;

        if (inAValley == false) {
            if (crnPoint.status == 'D' && crnPoint.avg == -1) {
                inAValley = true;
            }
        }
        else {
            if (crnPoint.status == 'U' && crnPoint.avg == -1) {
                inAValley = false;
                valley++;
            }
        }

        lastPoint = crnPoint;
    }
    printf("%d\n", valley);
    return 0;
}
