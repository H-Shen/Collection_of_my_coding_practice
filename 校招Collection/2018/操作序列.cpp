// https://www.nowcoder.com/practice/b53bda356a494154b6411d80380295f5

#include <deque>
#include <cstdio>

using namespace std;

int main() {

    int n, temp;
    scanf("%d", &n);
    bool order = true;
    deque<int> A;
    while (n--) {
        scanf("%d", &temp);
        if (order) {
            A.push_back(temp);
            order = false;
        } else {
            A.push_front(temp);
            order = true;
        }
    }

    // output
    bool firstItem = true;
    if (order) {
        for (const int &it : A) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", it);
        }
    } else {
        for (auto it = A.crbegin(); it != A.crend(); ++it) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", *it);
        }
    }
    printf("\n");
    return 0;
}