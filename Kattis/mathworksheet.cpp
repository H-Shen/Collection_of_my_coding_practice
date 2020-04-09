// https://open.kattis.com/problems/mathworksheet
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 5;
constexpr int MAX_COLUMN_A_LINE = 50;
char op[MAXN];

struct Node {
    ll val;
    string to_string;
};


int main() {

    int n;
    ll a, b;
    int max_size;
    string temp_str;
    bool first_case = true;

    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        if (first_case) {
            first_case = false;
        } else {
            printf("\n");
        }

        vector<Node> A(n);
        max_size = numeric_limits<int>::min();
        for (auto &i : A) {
            scanf("%lld %s %lld", &a, op, &b);
            if (strcmp(op, "*") == 0) {
                i.val = a * b;
            } else if (strcmp(op, "+") == 0) {
                i.val = a + b;
            } else {
                i.val = a - b;
            }
            i.to_string = to_string(i.val);
            max_size = max(max_size, static_cast<int>(i.to_string.size()));
        }
        for (auto &i : A) {
            while (static_cast<int>(i.to_string.size()) < max_size) {
                i.to_string = ' ' + i.to_string;
            }
        }

        // max_size * N + (N - 1) <= 50
        // (max_size + 1) * N <= 51
        // N <= 51 / (max_size + 1)
        int N = (MAX_COLUMN_A_LINE + 1) / (max_size + 1);
        while ( max_size * N + (N - 1) > MAX_COLUMN_A_LINE ) {
            --N;
        }
        int counter = 0;
        bool first_item = true;
        for (const auto &i : A) {
            if (first_item) {
                first_item = false;
            } else {
                printf(" ");
            }
            printf("%s", i.to_string.c_str());
            ++counter;
            if (counter == N) {
                printf("\n");
                counter = 0;
                first_item = true;
            }
        }
        if (counter != 0) {
            printf("\n");
        }
    }
    return 0;
}
