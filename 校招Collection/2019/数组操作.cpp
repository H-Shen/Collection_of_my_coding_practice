// https://www.nowcoder.com/practice/325483e19dab4609baf00157e5ebeb6f

#include <cstdio>
#include <deque>

using namespace std;
deque<int> A;

int main() {

    int n;
    while (~scanf("%d", &n)) {
        if (n & 1) {
            A.push_back(n);
        } else {
            A.push_front(n);
        }
    }

    bool firstItem = true;
    for (const int &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");
    return 0;
}