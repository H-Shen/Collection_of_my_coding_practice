#include <cstdio>
// https://ac.nowcoder.com/acm/problem/14610

#include <algorithm>
#include <vector>

using namespace std;

vector <int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

constexpr int N = 2;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        vector <int> a(N);
        for (auto &p : a) {
            scanf("%d", &p);
        }
        if (a == vector <int> {1, 0}) {
            printf("1\n");
        } else if (a == vector <int> {2, 1}) {
            printf("0\n");
        } else {
            auto it = search(A.begin(), A.end(), a.begin(), a.end());
            printf("%d\n", A.at(distance(A.begin(), it) + N));
        }
    }
    return 0;
}