#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
char s0[MAXN], s1[MAXN];

struct Stu {
    string name;
    vector<string> illegalStuff;
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    unordered_set<string> illegalStuff;
    string tmp;

    while (M--) {
        scanf("%s", s0);
        tmp = s0;
        illegalStuff.insert(tmp);
    }

    int k;
    string tmpStuffId;
    vector<Stu> result;
    while (N--) {
        scanf("%s %d", s0, &k);
        Stu tmpStu;
        tmpStu.name = s0;
        while (k--) {
            scanf("%s", s1);
            tmpStuffId = s1;
            if (illegalStuff.find(tmpStuffId) != illegalStuff.end()) {
                tmpStu.illegalStuff.push_back(tmpStuffId);
            }
        }
        if (!tmpStu.illegalStuff.empty()) {
            result.push_back(tmpStu);
        }
    }
    int len = static_cast<int>(result.size());
    int totalStuff = 0;
    int i, j, illegalStuffLen;
    for (i = 0; i < len; ++i) {
        printf("%s: ", result[i].name.c_str());
        illegalStuffLen = static_cast<int>(result[i].illegalStuff.size());
        totalStuff += illegalStuffLen;
        for (j = 0; j < illegalStuffLen - 1; ++j) {
            printf("%s ", result[i].illegalStuff[j].c_str());
        }
        printf("%s\n", result[i].illegalStuff[illegalStuffLen - 1].c_str());
    }
    printf("%d %d\n", len, totalStuff);

    return 0;
}