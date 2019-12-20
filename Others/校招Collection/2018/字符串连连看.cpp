// https://www.nowcoder.com/practice/22d33f7d65b84a759babae4001e87740

#include <bits/stdc++.h>

using namespace std;
const string pattern("(\\w)\\1{2,}");
const regex r(pattern);

int main() {
    string s;
    smatch result;
    getline(cin, s);
    while (regex_search(s, result, r)) {
        s.erase(result.prefix().length(), 3);
    }
    cout << s << endl;

    return 0;
}
