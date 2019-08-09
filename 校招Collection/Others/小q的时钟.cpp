// https://ac.nowcoder.com/acm/problem/15980

#include <string>
#include <iostream>

using namespace std;
using ll = long long;

string conv(ll a)
{
    string res = to_string(a);
    if (res.size() == 1)
    {
        res = "0" + res;
    }
    return res;
}

int main()
{
    ll Start, End, Time, Hour, Minute, Second;
    while (cin >> Start >> End)
    {
        Time = End - Start;
        Hour = Time / 3600;
        Minute = (Time % 3600) / 60;
        Second = Time - Hour * 3600 - Minute * 60;
        cout << conv(Hour) << ":" << conv(Minute) << ":" << conv(Second) << endl;
    }

    return 0;
}