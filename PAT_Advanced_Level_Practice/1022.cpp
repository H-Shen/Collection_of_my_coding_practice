#include <bits/stdc++.h>


using namespace std;

const int MAXN = 500, item = 6, interval = 3;

unordered_map<string, unordered_set<string> > titleList, authorList, keyWordList, publisherList;
unordered_map<int, unordered_set<string> > publishYearList;
vector<string> tempList;

int main() {

    int m, n, i;
    string str, bookId;
    scanf("%d", &m);
    getchar();

    while (m--) {

        for (i = 0; i < item; i++) {

            char s[MAXN];
            scanf("%[^\n]", s);
            getchar();
            str = s;

            if (i == 0)
                bookId = str;
            else if (i == 1)
                titleList[str].insert(bookId);
            else if (i == 2)
                authorList[str].insert(bookId);
            else if (i == 3) {
                vector<string> keyWordSave;
                istringstream ss(str);
                do {
                    string keyWordTemp;
                    ss >> keyWordTemp;
                    keyWordSave.push_back(keyWordTemp);
                } while (ss);
                keyWordSave.pop_back();
                for (auto &j : keyWordSave) {
                    keyWordList[j].insert(bookId);
                }
            } else if (i == 4) {
                publisherList[str].insert(bookId);
            } else {
                publishYearList[stoi(str, nullptr, 16)].insert(bookId);
            }
        }
    }

    scanf("%d", &n);
    getchar();

    while (n--) {

        char s[MAXN];
        scanf("%[^\n]", s);
        getchar();
        str = s;
        string query(str, interval);
        vector<string>().swap(tempList);

        switch (str[0]) {
            case '1':
                copy(titleList[query].begin(), titleList[query].end(), back_inserter(tempList));
                break;
            case '2':
                copy(authorList[query].begin(), authorList[query].end(), back_inserter(tempList));
                break;
            case '3':
                copy(keyWordList[query].begin(), keyWordList[query].end(), back_inserter(tempList));
                break;
            case '4':
                copy(publisherList[query].begin(), publisherList[query].end(), back_inserter(tempList));
                break;
            default:
                int queryInt = stoi(query, nullptr, 16);
                copy(publishYearList[queryInt].begin(), publishYearList[queryInt].end(), back_inserter(tempList));
        }

        printf("%s\n", str.c_str());
        if (tempList.empty())
            printf("Not Found\n");
        else {
            sort(tempList.begin(), tempList.end());
            for (auto &j : tempList)
                printf("%s\n", j.c_str());
        }
    }
    return 0;
}