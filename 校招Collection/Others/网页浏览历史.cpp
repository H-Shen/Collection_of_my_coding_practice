// https://www.nowcoder.com/practice/588d31d72721414584679ad7d32a6a93

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int main() {

    int n, pos;
    string tempStr;

    while (~scanf("%d", &n)) {

        vector<string> webList;
        pos = 0;

        while (n--) {

            char a[maxn], b[maxn];
            scanf("%s", a);

            if (strcmp(a, "VISIT") == 0) {
                scanf("%s", b);
                tempStr = b;
                if (pos != (int) webList.size()) {
                    vector<string> webListTemp(webList.begin(), webList.begin() + pos);
                    webList = webListTemp;
                }
                webList.push_back(tempStr);
                pos++;
                printf("%s\n", b);
            } else if (strcmp(a, "BACK") == 0) {
                if (pos == 0 || pos == 1) {
                    printf("ignore\n");
                } else {
                    pos--;
                    printf("%s\n", webList[pos - 1].c_str());
                }
            } else if (strcmp(a, "FORWARD") == 0) {
                if (pos == (int) webList.size()) {
                    printf("ignore\n");
                } else {
                    pos++;
                    printf("%s\n", webList[pos - 1].c_str());
                }
            }

        }
        putchar('\n');
    }
    return 0;
}