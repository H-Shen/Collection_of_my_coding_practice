#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    // stmt[i] > 0 means "+k": they say “k is good”
    // stmt[i] < 0 means "-k": they say “-stmt[i] is wolf”
    std::vector<int> stmt(N+1);
    for (int i = 1; i <= N; ++i) {
        char sign;
        int x;
        std::cin >> sign >> x;
        stmt[i] = (sign=='+' ? x : -x);
    }

    std::pair<int,int> best = {N+1, N+1};
    for (int i = 1; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            int total_false = 0;
            int wolf_false = 0;

            for (int k = 1; k <= N; ++k) {
                int s = stmt[k];
                bool is_true;
                if (s > 0) {
                    // “s is good”
                    is_true = (s != i && s != j);
                } else {
                    // “-s is wolf”
                    int t = -s;
                    is_true = (t == i || t == j);
                }
                if (!is_true) {
                    ++total_false;
                    if (k==i || k==j) ++wolf_false;
                }
            }

            // exactly 2 liars, exactly one wolf among them
            if (total_false==2 && wolf_false==1) {
                best = std::min(best, std::make_pair(i,j));
            }
        }
    }

    if (best.first <= N) {
        std::cout << best.first << " " << best.second;
    } else {
        std::cout << "No Solution";
    }
    return 0;
}
