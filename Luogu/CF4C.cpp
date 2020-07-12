#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    unordered_map<string, int> A;
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (A.find(s) != A.end()) {
            ++A[s];
            cout << s << A[s] << '\n';
        } else {
            A[s] = 0;
            cout << "OK" << '\n';
        }
    }

    return 0;
}