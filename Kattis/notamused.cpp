// https://open.kattis.com/problems/notamused
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 30;
char operation[MAXN];
char name[MAXN];

bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    return (lhs.first < rhs.first);
}

int main() {

    int day = 1;
    int time;
    bool firstItem = true;
    while (true) {
        // OPEN
        if (scanf("%s", operation) == EOF) {
            break;
        }
        unordered_map<string, int> stats;
        unordered_map<string, int> enterList;
        while (true) {
            scanf("%s", operation);
            if (strcmp(operation, "CLOSE") == 0) {
                break;
            } else if (strcmp(operation, "ENTER") == 0) {
                scanf("%s %d", name, &time);
                enterList[name] = time;
            } else {
                scanf("%s %d", name, &time);
                stats[name] += (time - enterList[name]);
                enterList.erase(name);
            }
        }
        // sort
        vector<pair<string, int> > output;
        for (const auto &i : stats) {
            output.emplace_back(i.first, i.second);
        }
        sort(output.begin(), output.end(), cmp);
        // output
        if (firstItem) {
            firstItem = false;
        } else {
            printf("\n");
        }
        printf("Day %d\n", day);
        for (const auto &i : output) {
            printf("%s $%.2lf\n", i.first.c_str(), i.second * 0.1);
        }
        ++day;
    }

    return 0;
}
