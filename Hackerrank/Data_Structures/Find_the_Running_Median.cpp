#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector <int> a(n);
    int len = n;
    int i, midVal;

    for (i = 0; i < len; ++i) {
        scanf("%d", &a[i]);
    }

    priority_queue <int> smallerHeap;
    priority_queue <int, vector <int>, greater<int> > greaterHeap;

    for (i = 0; i < len; ++i) {

        if (i == 0) {
            midVal = a[i];
            printf("%.1lf\n", (double)midVal);
            continue;
        }

        if (a[i] > midVal) {
            greaterHeap.push(a[i]);
        }
        else {
            smallerHeap.push(a[i]);
        }

        if ( greaterHeap.size() == smallerHeap.size() + 2 ) {
            smallerHeap.push(midVal);
            midVal = greaterHeap.top();
            greaterHeap.pop();
        }
        else if ( smallerHeap.size() > greaterHeap.size() ) {
            greaterHeap.push(midVal);
            midVal = smallerHeap.top();
            smallerHeap.pop();
        }

        if (i % 2 == 0) {
            printf("%.1lf\n", (double)midVal);
        }
        else {
            printf("%.1lf\n", (midVal + greaterHeap.top()) / 2.0);
        }
    }

    return 0;
}
