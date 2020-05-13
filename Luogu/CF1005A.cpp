#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int length = -1;
    vector<int> output;
    for (auto &i : A) {
        if (length == -1) {
            length = 1;
        } else if (i == 1) {
            output.emplace_back(length);
            length = 1;
        } else {
            ++length;
        }
    }
    output.emplace_back(length);
    printf("%zd\n", output.size());
    bool first_item = true;
    for (const auto &i : output) {
        if (first_item) {
            first_item = false;
        } else {
            putchar(' ');
        }
        printf("%d", i);
    }
    printf("\n");

    return 0;
}