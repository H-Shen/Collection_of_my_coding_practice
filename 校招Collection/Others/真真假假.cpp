// https://ac.nowcoder.com/acm/problem/15517

#include <iostream>
#include <string>
#include <unordered_set>
#include <regex>


using namespace std;

int main()
{
    string a  = "algorithm, bitset, cctype, cerrno, clocale, cmath, complex, cstdio, cstdlib, cstring, ctime, deque, exception, fstream, functional, limits, list, map, iomanip, ios, iosfwd, iostream, istream, ostream, queue, set, sstream, stack, stdexcept, streambuf,string, utility, vector, cwchar, cwctype";
    regex r(R"(\w+)");
    unordered_set <string> Table;
    for (sregex_iterator it(a.begin(), a.end(), r), end_it; it != end_it; ++it)
    {
        Table.insert(it->str());
    }

    int T;
    string query;
    cin >> T;
    while (T--)
    {
        cin >> query;
        if (Table.find(query) != Table.end())
        {
            cout << "Qian";
        }
        else
        {
            cout << "Kun";
        }
        cout << endl;
    }
    return 0;
}