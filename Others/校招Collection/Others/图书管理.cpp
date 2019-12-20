// https://ac.nowcoder.com/acm/contest/954/B

include <bits/stdc++.h>

using namespace std;
const int MAXN = 210;
char s[MAXN];
char bookname[MAXN];

int main() {

    int n;
    unordered_set<string> A;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%[^\n]", s);
        switch (s[0]) {
            case 'a':
                strcpy(bookname, s + 4);
                A.insert(bookname);
                break;
            default:
                strcpy(bookname, s + 5);
                printf(A.find(bookname) == A.end() ?  "no\n" : "yes\n");
                break;
        }
        getchar();
    }

    return 0;
}