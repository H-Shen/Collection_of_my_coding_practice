#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int t, n, gender;
    bool first_item;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> boys;
        vector<int> girls;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &gender);
            if (gender == 1) {
                boys.emplace_back(i);
            } else {
                girls.emplace_back(i);
            }
        }
        vector<double> height(n);
        for (auto &i : height) {
            scanf("%lf", &i);
        }
        vector<double> girls_height(girls.size());
        for (size_t i = 0; i != girls.size(); ++i) {
            girls_height.at(i) = height.at(girls.at(i));
        }
        sort(girls_height.begin(), girls_height.end());

        vector<double> boys_height(boys.size());
        for (size_t i = 0; i != boys.size(); ++i) {
            boys_height.at(i) = height.at(boys.at(i));
        }
        sort(boys_height.begin(), boys_height.end());

        // output
        first_item = true;
        for (auto &i : girls_height) {
            if (first_item) {
                first_item = false;
            } else {
                printf(" ");
            }
            cout << i;
        }
        printf("\n");
        first_item = true;
        for (auto &i : boys_height) {
            if (first_item) {
                first_item = false;
            } else {
                printf(" ");
            }
            cout << i;
        }
        printf("\n");
    }

    return 0;
}