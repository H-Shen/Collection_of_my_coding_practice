// https://www.nowcoder.com/practice/286af664b17243deb745f69138f8a800

#include <cstdio>
#include <string>
#include <unordered_set>

using namespace std;

const int maxLen = 600, maxQueryLen = 20;

int main() {

    int i, len;
    string str, crnStr;
    char s[maxLen], query[maxQueryLen];
    bool inQuota;

    while (scanf("%[^\n]", s) != EOF) {

        getchar();
        str = s;
        len = static_cast<int>(str.size());
        crnStr = "";
        inQuota = false;
        unordered_set<string> res;

        for (i = 0; i < len; i++) {
            if (str[i] == '\"') {
                inQuota = !inQuota;
            } else if (inQuota)
                crnStr += str[i];
            else {
                if (str[i] == ',') {
                    res.insert(crnStr);
                    crnStr = "";
                } else
                    crnStr += str[i];
            }
        }
        if (!crnStr.empty())
            res.insert(crnStr);

        scanf("%[^\n]", query);
        getchar();
        str = query;

        if (res.find(str) == res.end())
            printf("Important!\n");
        else
            printf("Ignore\n");
    }
    return 0;
}