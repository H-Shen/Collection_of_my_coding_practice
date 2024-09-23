// https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN{64};

inline static
int findNumberOf1(const int &num) {
    return static_cast<int>(bitset<MAXN>(static_cast<unsigned long long>(num)).count());
}

int main() {

    int num;
    while (cin >> num) {
        cout << findNumberOf1(num) << endl;
    }

    return 0;
}