#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int> > A(n, vector<int>(m));
    for (auto &i : A) {
        for (auto &j : i) {
            scanf("%d", &j);
        }
    }
    vector<double> output;
    int sum;
    for (const auto &i : A) {
        sum = accumulate(i.begin(), i.end(), 0);
        sum -= *max_element(i.begin(), i.end());
        sum -= *min_element(i.begin(), i.end());
        output.emplace_back(sum * 1.0 / (m - 2));
    }
    printf("%.2lf\n", *max_element(output.begin(), output.end()));
    return 0;
}
