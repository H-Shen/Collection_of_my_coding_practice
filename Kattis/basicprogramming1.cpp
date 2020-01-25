// https://open.kattis.com/problems/basicprogramming1
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int N, t;
    scanf("%d %d", &N, &t);
    vector<ll> A(N);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    if (t == 1) {
        printf("7\n");
    } else if (t == 2) {
        if (A.at(0) > A.at(1)) {
            printf("Bigger\n");
        } else if (A.at(0) == A.at(1)) {
            printf("Equal\n");
        } else {
            printf("Smaller\n");
        }
    } else if (t == 3) {
        vector<ll> B = {A.at(0), A.at(1), A.at(2)};
        sort(B.begin(), B.end());
        printf("%lld\n", B.at(1));
    } else if (t == 4) {
        ll sum = 0;
        for (const auto &i : A) {
            sum += i;
        }
        printf("%lld\n", sum);
    } else if (t == 5) {
        ll sum = 0;
        for (const auto &i : A) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        printf("%lld\n", sum);
    } else if (t == 6) {
        string s;
        for (const auto &i : A) {
            s += static_cast<char>((i % 26) + 'a');
        }
        printf("%s\n", s.c_str());
    } else if (t == 7) {
        unordered_set<int> store_index;
        int i;
        i = 0;
        store_index.insert(i);
        while (true) {
            try {
                i = A.at(i);
                if (store_index.find(i) != store_index.end()) {
                    printf("Cyclic\n");
                    break;
                } else {
                    store_index.insert(i);
                }
                if (i == N - 1) {
                    printf("Done\n");
                    break;
                }
            } catch (...) {
                printf("Out\n");
                break;
            }
        }
    }

    return 0;
}
