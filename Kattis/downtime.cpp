// https://open.kattis.com/problems/downtime
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    double k;
    scanf("%d %lf", &n, &k);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int minimal_servers_needed = -1;
    int number_of_requests_before_i_happened;
    for (auto i = A.begin(); i != A.end(); ++i) {
        number_of_requests_before_i_happened = lower_bound(A.begin(), A.end(), (*i) + 1000) - i;
        minimal_servers_needed = max(minimal_servers_needed, (int)ceil(number_of_requests_before_i_happened / k));
    }
    printf("%d\n", minimal_servers_needed);
    return 0;
}
