#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 205;
char s[MAXN];

int main() {

    string str;
    while (~scanf("%s", s)) {
        str += string(s);
    }
    int n;
    for (n = 1;; ++n) {
        if (n * n == static_cast<int>(str.size())) {
            break;
        }
    }
    int counter = 0;
    vector<int> A;
    bool one = false;
    for (size_t i = 0; i != str.size(); ++i) {
        // 1
        if (one) {
            if (str.at(i) == '1') {
                ++counter;
            } else {
                A.emplace_back(counter);
                counter = 1;
                one = false;
            }
        }
        // 0
        else {
            if (str.at(i) == '0') {
                ++counter;
            } else {
                A.emplace_back(counter);
                counter = 1;
                one = true;
            }
        }
    }
    A.emplace_back(counter);
    printf("%d ", n);
    bool first_item = true;
    for (const auto &i : A) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");


    return 0;
}