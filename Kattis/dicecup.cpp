// https://open.kattis.com/problems/dicecup
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    unordered_map <int, int> freq;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ++freq[i + j];
        }
    }
    int maxVal = -1;
    for (const auto &i : freq)
    {
        maxVal = max(maxVal, i.second);
    }
    vector <int> rank;
    for (const auto &i : freq)
    {
        if (i.second == maxVal)
        {
            rank.push_back(i.first);
        }
    }
    sort(rank.begin(), rank.end());
    for (const auto &i : rank)
    {
        cout << i << endl;
    }
    return 0;
}
