// https://open.kattis.com/problems/planina
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    // Python3: print(pow(pow(2, int(input())) + 1, 2))
    vector<int> A = {
            9,
            25,
            81,
            289,
            1089,
            4225,
            16641,
            66049,
            263169,
            1050625,
            4198401,
            16785409,
            67125249,
            268468225,
            1073807361
    };
    int n;
    cin >> n;
    cout << A.at(n - 1) << endl;

    return 0;
}
