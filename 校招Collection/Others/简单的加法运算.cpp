// https://ac.nowcoder.com/acm/problem/14341

#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using ll = long long;

int main()
{
    string k, tmpStr;
    int n;
    cin >> n;
    getchar();

    ll s;
    while (n--) {
        s = 0;
        getline(cin, k);
        istringstream ss(k);
        while (ss >> tmpStr) {
            s = s + stol(tmpStr);
        }
        cout << s << endl;
    }
}