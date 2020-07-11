#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

vector<vector<int> > A;

int main(int argc, char *argv[]) {

    A.emplace_back(vector<int>{0, 1, 2});
    A.emplace_back(vector<int>{1, 0, 2});
    A.emplace_back(vector<int>{1, 2, 0});
    A.emplace_back(vector<int>{2, 1, 0});
    A.emplace_back(vector<int>{2, 0, 1});
    A.emplace_back(vector<int>{0, 2, 1});
    int n, val;
    cin >> n >> val;
    n %= 6;
    cout << A.at(n).at(val) << '\n';
    return 0;
}