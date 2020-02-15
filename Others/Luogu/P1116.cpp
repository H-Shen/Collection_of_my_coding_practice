#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace BubbleSort {
    template<typename T>
    int sort(std::vector<T> &A) {
        bool flag = true; // A boolean flag indicates the array has to be sorted again if it is true
        int n = static_cast<int>(A.size());
        int counter = 0;
        while (flag) {
            flag = false;
            for (int i = 0; i < n - 1; ++i) {
                if (A.at(i) > A.at(i + 1)) {
                    flag = true;
                    std::swap(A.at(i), A.at(i + 1));
                    ++counter;
                }
            }
        }
        return counter;
    }
}

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    printf("%d\n", BubbleSort::sort(A));

    return 0;
}