// https://open.kattis.com/problems/abc

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 3;

int main()
{
    vector <int> A(maxn);
    for (int i = 0; i < maxn; ++i)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    unordered_map <char, int> Save;
    Save['A'] = A[0];
    Save['B'] = A[1];
    Save['C'] = A[2];

    string s;
    cin >> s;
    for (int i = 0; i < maxn - 1; ++i)
    {
        cout << Save[s[i]] << ' ';
    }
    cout << Save[s[maxn - 1]] << endl;
    return 0;
}
