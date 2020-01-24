// https://open.kattis.com/problems/ada
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, val;
    vector<int> A;
    vector<int> tail;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        A.emplace_back(val);
    }
    tail.emplace_back(A.back());
    vector<int> A_diff;

    int degree = 1;
    int length;
    while (true) {
        length = static_cast<int>(A.size());
        vector<int>().swap(A_diff);
        for (int i = 0; i < length - 1; ++i) {
            A_diff.emplace_back(A.at(i + 1) - A.at(i));
        }
        A = A_diff;
        tail.emplace_back(A.back());
        if (unordered_set(A_diff.begin(), A_diff.end()).size() == 1) {
            break;
        } else {
            ++degree;
        }
    }
    printf("%d %d\n", degree, accumulate(tail.begin(), tail.end(), 0));

    return 0;
}
