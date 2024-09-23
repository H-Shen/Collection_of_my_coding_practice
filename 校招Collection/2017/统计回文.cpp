// https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int n) {

    int i, j;
    bool res = true;
    if (n % 2 == 0) {
        for (i = 0, j = n - 1; i <= n / 2 - 1; i++, j--) {
            if (s[i] != s[j]) {
                res = false;
                break;
            }
        }
    } else {
        for (i = 0, j = n - 1; i <= (n - 1) / 2; i++, j--) {
            if (s[i] != s[j]) {
                res = false;
                break;
            }
        }
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    string a, b, c;
    int cnt = 0, i;
    cin >> a >> b;

    int len_a = a.size();
    int len = len_a + b.size();

    //TAIL
    c = a + b;
    if (isPalindrome(c, len))
        cnt++;

    //HEAD AND MID
    for (i = 0; i < len_a; i++) {
        string c0(a, 0, i);
        string c1(a, i);
        c = c0 + b + c1;
        if (isPalindrome(c, len))
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}