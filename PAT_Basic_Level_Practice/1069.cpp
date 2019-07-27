#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;
char cstr[maxn];

int main() {
    int M, N, S, i;
    scanf("%d %d %d", &M, &N, &S);
    unordered_map<string, bool> A;  //-1 for people who got the award
    string str;
    vector<string> strList(M + 5);
    vector<string> res;

    for (i = 1; i <= M; ++i) {
        scanf("%s", cstr);
        str = cstr;
        strList[i] = str;
        A[strList[i]] = false;
    }

    bool haveAns = false;
    for (i = S; i <= M;) {
        if (!A[strList[i]]) {
            A[strList[i]] = true;
            printf("%s\n", strList[i].c_str());
            haveAns = true;
            i += N;
        } else {
            i++;
        }
    }

    if (!haveAns) {
        printf("Keep going...\n");
    }
    return 0;
}