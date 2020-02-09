#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int T;
    scanf("%d", &T);
    int n;
    int val;
    while (T--) {
        gp_hash_table<int, int> temp_unmap;
        bool first_item = true;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &val);
            if (temp_unmap.find(val) == temp_unmap.end()) {
                if (first_item) {
                    first_item = false;
                } else {
                    printf(" ");
                }
                printf("%d", val);
                temp_unmap[val] = 1;
            }
        }
        printf("\n");
    }

    return 0;
}
