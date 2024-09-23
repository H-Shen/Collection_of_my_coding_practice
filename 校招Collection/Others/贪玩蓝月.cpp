// https://ac.nowcoder.com/acm/problem/15704

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T, N, a, b;
    string s;
    cin >> T;
    while (T--)
    {
        cin >> N;
        switch (N)
        {
            case 0:
                cin >> a >> b;
                cout << a + b << endl;
                break;
            case 1:
                cin >> s;
                cout << s.size() << endl;
        }
    }
}