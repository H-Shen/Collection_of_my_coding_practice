#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<string> A = {
        "January", "February", "March", "April", "May",
        "June", "July", "August", "September",
        "October", "November", "December"
};

int main() {

    string s;
    int k;
    cin >> s >> k;
    int index = (int)(find(A.begin(), A.end(), s) - A.begin() + k) % 12;
    cout << A.at(index) << endl;

    return 0;
}