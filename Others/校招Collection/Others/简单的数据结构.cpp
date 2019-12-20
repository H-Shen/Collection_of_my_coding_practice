// https://ac.nowcoder.com/acm/problem/14661

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, input, append;
    scanf("%d %d", &n, &m);
    deque <int> A;

    while (m--) {
        scanf("%d", &input);
        switch (input) {
        case 1 :
            scanf("%d", &append);
            A.push_front(append);
            break;
        case 2 :
            A.pop_front();
            break;
        case 3 :
            scanf("%d", &append);
            A.emplace_back(append);
            break;
        case 4 :
            A.pop_back();
            break;
        case 5 :
            reverse(A.begin(), A.end());
            break;
        case 6 :
            printf("%d\n", static_cast<int>(A.size()));;
            for (decltype(A.size()) i = 0; i < A.size() - 1; ++i) {
                printf("%d ", A[i]);
            }
            printf("%d\n", A[A.size() - 1]);
            break;
        case 7 :
            sort(A.begin(), A.end());
            break;
        }
    }
    return 0;
}