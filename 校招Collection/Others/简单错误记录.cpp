// https://www.nowcoder.com/practice/2baa6aba39214d6ea91a2e03dff3fbeb

#include <cstdio>
#include <cstring>

#include <string>
#include <deque>

using namespace std;

const int maxItem = 8, maxChar = 16, maxLen = 500;

string fileNameClean(string &s) {

    string result;
    int len = static_cast<int>(s.size());
    int i;
    int cnt = 0;
    for (i = len - 1; i >= 0; i--) {
        if (cnt >= maxChar || s[i] == '\\')
            break;
        else {
            result = s[i] + result;
            ++cnt;
        }
    }
    return result;
}

struct Log {
    string fileName;
    int lineNum = -1;
    int occurrenceCount = 1;
};

int main() {

    string s, fileName;
    int lineNum, i;
    int len = 0;
    bool haveAns;
    deque<Log> table;
    char str[maxLen];

    while (~scanf("%s %d", str, &lineNum)) {

        s = str;
        haveAns = false;
        fileName = fileNameClean(s);

        for (i = 0; i < len; i++) {
            if (table[i].fileName == fileName && table[i].lineNum == lineNum) {
                table[i].occurrenceCount++;
                haveAns = true;
                break;
            }
        }

        if (!haveAns) {
            Log temp;
            temp.fileName = fileName;
            temp.lineNum = lineNum;
            table.push_front(temp);
            ++len;
        }
        memset(str, 0, sizeof(str));
    }

    int start;
    start = (len >= 8) ? maxItem - 1 : len - 1;
    for (i = start; i >= 0; i--)
        printf("%s %d %d\n", table[i].fileName.c_str(), table[i].lineNum, table[i].occurrenceCount);
    return 0;
}