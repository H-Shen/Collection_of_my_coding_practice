#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    vector<int> A;
    while (~scanf("%d", &n)) {
        A.emplace_back(n);
    }
    A.pop_back();
    bool first_item = true;
    for (auto iter = A.crbegin(); iter != A.crend(); ++iter) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", *iter);
    }
    printf("\n");
    
    return 0;
}
