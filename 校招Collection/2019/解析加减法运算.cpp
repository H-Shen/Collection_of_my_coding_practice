// https://www.nowcoder.com/practice/e3aa42adf73248c58bdaaaa3be162f83

#include <string>
#include <iostream>
#include <regex>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string pattern("[+-]?[0-9]+");
    regex r(pattern);

    string s;
    cin >> s;
    int sum = 0;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        sum += stoi(it->str());
    }
    cout << sum << endl;
    return 0;
}