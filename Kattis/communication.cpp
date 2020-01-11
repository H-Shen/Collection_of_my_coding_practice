// https://open.kattis.com/problems/communication
//
#include<bits/stdc++.h>

using namespace std;
constexpr int maxn = 255;
unordered_map<int, int> A;

inline
auto f = [](const int &x)->int{
    return (x ^ (x << 1)) % 256;
};

int main() {

    for (int i = 0; i <= maxn; ++i) {
        A[f(i)] = i;
    }

    int n;
    scanf("%d", &n);
    vector<int> L(n);
    for (auto &i : L) {
        scanf("%d", &i);
    }
    bool firstItem = true;
    for (const auto &i : L) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
    return 0;
}
