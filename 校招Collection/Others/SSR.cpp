// https://ac.nowcoder.com/acm/problem/15713

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int cnt = 1;
    string s(3, 'A');
    unordered_map <string, int> A;

    for (; s[0] <= 'S'; ++s[0])
    {
        for (; s[1] <= 'S'; ++s[1])
        {
            for (; s[2] <= 'S'; ++s[2])
            {
                A[s] = cnt;
                ++cnt;
            }
            s[2] = 'A';
        }
        s[1] = 'A';
    }

    int n;
    cin >> n;
    string query;
    while (n--)
    {
        cin >> query;
        cout << A["SSR"] - A[query] << endl;
    }


    return 0;
}