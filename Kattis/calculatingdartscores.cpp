// https://open.kattis.com/problems/calculatingdartscores
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 20;

unordered_map<int, string> A;

void pre() {
    for (int i = 1; i <= MAXN; ++i) {
        A[i] = "single " + to_string(i);
    }
    for (int i = 1; i <= MAXN; ++i) {
        A[i * 2] = "double " + to_string(i);
    }
    for (int i = 1; i <= MAXN; ++i) {
        A[i * 3] = "triple " + to_string(i);
    }
}

int main() {

    pre();
    int n;
    scanf("%d", &n);

    for (const auto &a : A) {
        if (a.first == n) {
            printf("%s\n", a.second.c_str());
            return 0;
        }
    }
    

    for (const auto &a : A) {
        for (const auto &b : A) {
            if (a.first + b.first == n) {
                printf("%s\n%s\n", a.second.c_str(), b.second.c_str());
                return 0;
            }
        }
    }
    
    for (const auto &a : A) {
        for (const auto &b : A) {
            for (const auto &c : A) {
                if (a.first + b.first + c.first == n) {
                    printf("%s\n%s\n%s\n", a.second.c_str(), b.second.c_str(), c.second.c_str());
                    return 0;
                }
            }
        }
    }
    printf("impossible\n");
    return 0;
}
