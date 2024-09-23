#include <bits/stdc++.h>


using namespace std;
const int MAXN = 15;
char s[MAXN], s1[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    string name, passwd;

    int i, j;
    int len;
    vector<pair<string, string> > res;
    bool haveChange;

    for (j = 0; j < n; ++j) {
        scanf("%s %s", s, s1);
        name = s;
        passwd = s1;
        len = passwd.size();
        haveChange = false;

        for (i = 0; i < len; ++i) {
            if (passwd[i] == '1') {
                passwd[i] = '@';
                haveChange = true;
            } else if (passwd[i] == '0') {
                passwd[i] = '%';
                haveChange = true;
            } else if (passwd[i] == 'l') {
                passwd[i] = 'L';
                haveChange = true;
            } else if (passwd[i] == 'O') {
                passwd[i] = 'o';
                haveChange = true;
            }
        }

        if (haveChange) {
            pair<string, string> tmp = make_pair(name, passwd);
            res.push_back(tmp);
        }
    }

    if (res.empty() && n != 1) {
        printf("There are %d accounts and no account is modified\n", n);
    } else if (res.empty() && n == 1) {
        printf("There is 1 account and no account is modified\n");
    } else {
        printf("%d\n", static_cast<int>(res.size()));
        for (const auto &p : res) {
            printf("%s %s\n", p.first.c_str(), p.second.c_str());
        }
    }
    return 0;
}