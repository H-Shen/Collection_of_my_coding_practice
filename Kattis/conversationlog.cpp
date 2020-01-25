// https://open.kattis.com/problems/conversationlog
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAX_LENGTH = 2000050;
const char delim[] = " ";
char *ptr = nullptr;
char s[MAX_LENGTH];
unordered_map<string, unordered_map<string, int> > name2wordsFreq;
unordered_map<string, int> freqOfWordsUsedByEveryone;

inline static
unordered_set<string> setIntersection(const unordered_set<string> &lhs, const unordered_map<string, int> &rhs) {
    unordered_set<string> result;
    for (const auto &i : lhs) {
        if (rhs.find(i) != rhs.end()) {
            result.insert(i);
        }
    }
    return result;
}

inline static
unordered_set<string> filterWordsUsedByEveryone() {
    unordered_set<string> wordsUsedByEveryone;
    bool firstItem = true;
    for (const auto &i : name2wordsFreq) {
        if (firstItem) {
            for (const auto &j : i.second) {
                wordsUsedByEveryone.insert(j.first);
            }
            firstItem = false;
        } else {
            wordsUsedByEveryone = setIntersection(wordsUsedByEveryone, i.second);
        }
    }
    return wordsUsedByEveryone;
}

inline static
bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    if (lhs.second == rhs.second) {
        return (lhs.first < rhs.first);
    }
    return (lhs.second > rhs.second);
}

int main() {

    int n;
    bool firstItem;
    string name;
    scanf("%d", &n);
    getchar();

    while (n--) {

        firstItem = true;
        scanf("%[^\n]", s);
        getchar();

        // Split the string
        ptr = strtok(s, delim);
        while (ptr) {
            if (firstItem) {
                firstItem = false;
                name = ptr;
            } else {
                ++name2wordsFreq[name][ptr];
            }
            ptr = strtok(nullptr, delim);
        }
    }

    // filter
    unordered_set<string> wordsUsedByEveryone = filterWordsUsedByEveryone();

    if (wordsUsedByEveryone.empty()) {

        // output
        printf("ALL CLEAR\n");

    } else {

        // stats
        for (const auto &i : name2wordsFreq) {
            for (const auto &j : i.second) {
                if (wordsUsedByEveryone.find(j.first) != wordsUsedByEveryone.end()) {
                    freqOfWordsUsedByEveryone[j.first] += j.second;
                }
            }
        }
        // sort by freq
        vector<pair<string, int> > result(freqOfWordsUsedByEveryone.size());
        auto resultIter = result.begin();
        for (const auto &i : freqOfWordsUsedByEveryone) {
            *resultIter = make_pair(i.first, i.second);
            ++resultIter;
        }
        sort(result.begin(), result.end(), cmp);

        // output
        for (const auto &i : result) {
            printf("%s\n", i.first.c_str());
        }
    }

    return 0;
}
