#include <bits/extc++.h>

using namespace std;
using ll = long long;

vector<string> array_of_presidents = {"Washington", "Adams", "Jefferson",
                                      "Madison",
                                      "Monroe", "Adams", "Jackson", "Van Buren",
                                      "Harrison", "Tyler", "Polk", "Taylor",
                                      "Fillmore",
                                      "Pierce", "Buchanan", "Lincoln",
                                      "Johnson", "Grant",
                                      "Hayes", "Garfield", "Arthur",
                                      "Cleveland",
                                      "Harrison", "Cleveland", "McKinley",
                                      "Roosevelt",
                                      "Taft", "Wilson", "Harding", "Coolidge",
                                      "Hoover",
                                      "Roosevelt", "Truman", "Eisenhower",
                                      "Kennedy",
                                      "Johnson", "Nixon", "Ford", "Carter",
                                      "Reagan"};


int main() {

    int n;
    cin >> n;
    cout << array_of_presidents.at(n - 1) << '\n';

    return 0;
}
