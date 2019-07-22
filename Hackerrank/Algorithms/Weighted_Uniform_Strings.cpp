#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int MAXN = 100005, GAP = 96;

unordered_set <int> save;
char s[MAXN];
string str;
string currentStr;

void calWeight(string &k) {

    int len = k.size();
    int interval = k[0] - GAP;
    int currentVal = interval;
    int i;
    save.insert(currentVal);
    for (i = 1; i < len; i++) {
        currentVal += interval;
        save.insert(currentVal);
    }
}

int main() {

    scanf("%s", s);
    str = s;
    int len = str.size();
    char currentChar = s[0];
    currentStr = currentStr + currentChar;
    int currentWeight;

    int i;
    for (i = 1; i < len - 1; i++) {
        if (s[i] == s[i - 1]) {
            currentStr = currentStr + s[i];
        }
        else {
            calWeight(currentStr);
            currentChar = s[i];
            currentStr = s[i];
        }
    }

    if (len > 1) {
        if (s[i] == s[i - 1]) {
            currentStr = currentStr + s[i];
            calWeight(currentStr);
        }
        else {
            calWeight(currentStr);
            currentWeight = s[i] - GAP;
            save.insert(currentWeight);
        }
    }
    else {
        currentWeight = currentChar - GAP;
        save.insert(currentWeight);
    }

    int query, queryNum;
    scanf("%d", &query);
    for (i = 0; i < query; i++) {
        scanf("%d", &queryNum);
        if (save.find(queryNum) == save.end())
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}

