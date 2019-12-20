// https://ac.nowcoder.com/acm/problem/14737

#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int main()
{
    string x;
    cin >> x;
    unordered_set <char> A (x.begin(), x.end());
    if (A.size() == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}