// https://open.kattis.com/problems/basicprogramming2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int N, t;
    int x, y;
    scanf("%d %d", &N, &t);
    vector<ll> A(N);
    unordered_map<ll, ll> temp_unordered_map;
    for (auto &i : A) {
        scanf("%lld", &i);
        ++temp_unordered_map[i];
    }
    if (t == 1) {
        bool haveAns = false;
        for (const auto &[key, value] : temp_unordered_map) {
            x = key;
            y = 7777 - x;
            if (x != y && temp_unordered_map.find(y) != temp_unordered_map.end()) {
                haveAns = true;
                break;
            }
        }
        if (haveAns) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else if (t == 2) {
        if (static_cast<int>(temp_unordered_map.size()) == N) {
            printf("Unique\n");
        } else {
            printf("Contains duplicate\n");
        }
    } else if (t == 3) {
        bool haveAns = false;
        bool firstItem = true;
        vector<ll> output;
        unordered_set<ll> output_unique;
        for (const auto &i : A) {
            if (temp_unordered_map[i] > N / 2) {
                haveAns = true;
                if (output_unique.find(i) != output_unique.end()) {
                    continue;
                } else {
                    output_unique.insert(i);
                    output.emplace_back(i);
                }
            }
        }
        if (!haveAns) {
            printf("-1\n");
        } else {
            for (const auto &i : output) {
                haveAns = true;
                if (firstItem) {
                    firstItem = false;
                } else {
                    printf(" ");
                }
                printf("%lld", i);
            }
        }
    } else if (t == 4) {
        sort(A.begin(), A.end());
        if (N % 2 == 0) {
            printf("%lld %lld\n", A.at(N / 2 - 1), A.at(N / 2));
        } else {
            printf("%lld\n", A.at(N / 2));
        }
    } else {
        sort(A.begin(), A.end());
        bool firstItem = true;
        for (const auto &i : A) {
            if (i >= 100 && i <= 999) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    printf(" ");
                }
                printf("%lld", i);
            }
        }
        printf("\n");
    }


    return 0;
}
