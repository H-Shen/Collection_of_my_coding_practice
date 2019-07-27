#include <cstdio>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, i, cnt;
    string input;

    cin >> n;
    getchar();
    string str;

    for (i = 0; i < n; i++) {
        getline(cin, input);
        str += " " + input + " ";
    }

    cin >> m;
    while (m--) {

        cin >> input;
        string pattern = "(\\b|\\W)" + input + "(\\b|\\W)";
        regex r(pattern);
        cnt = 0;

        for (sregex_iterator it(str.begin(), str.end(), r), end_it; it != end_it; ++it) {
            cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}
