#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int s1, s2, s3;
    unordered_map<int, int> A;
    scanf("%d %d %d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; ++i) {
        for (int j = 1; j <= s2; ++j) {
            for (int k = 1; k <= s3; ++k) {
                ++A[i + j + k];
            }
        }
    }
    int max_freq = -1;
    for (const auto &[k, v] : A) {
        max_freq = max(max_freq, v);
    }
    int min_sum = numeric_limits<int>::max();
    for (const auto &[k, v] : A) {
        if (v == max_freq) {
            min_sum = min(min_sum, k);
        }
    }
    printf("%d\n", min_sum);

    return 0;
}
