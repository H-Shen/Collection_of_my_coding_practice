// https://www.nowcoder.com/practice/b07c464a107e421ebbd2c82aebd42e39

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n1, n2;
    string s1, s2;
    cin >> n1 >> n2;
    cin >> s1 >> s2;
    cout << boolalpha << bool((n1 == n2) && (is_permutation(s1.begin(), s1.end(), s2.begin()))) << endl;

    return 0;
}