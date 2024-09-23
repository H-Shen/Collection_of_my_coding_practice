// https://www.nowcoder.com/practice/79c562297c0e4ff0952ef39ecde1bd6b

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    n %= static_cast<int>(s.size());
    rotate(begin(s), begin(s) + n, end(s));
    cout << s << endl;
    return 0;
}