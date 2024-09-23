// Union find set

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXLEN = 10;
char name1[MAXLEN];
char name2[MAXLEN];

namespace UnionFindSet {

    constexpr int MAXN = 2000005;
    vector<int> father(MAXN); // Father nodes
    vector<int> Rank(MAXN); // Rank

    int find(int x) {
        if (x != father.at(x))
            father.at(x) = find(father.at(x));
        return father.at(x);
    }

    void merge(int x, int y) {

        x = find(x);
        y = find(y);

        if (Rank.at(x) > Rank.at(y)) {
            father.at(y) = x;
        } else {
            father.at(x) = y;
            if (Rank.at(x) == Rank.at(y))
                ++Rank.at(y);
        }
    }

    void reset() {
        for (int i = 0; i < MAXN; i++) {
            father.at(i) = i;
            Rank.at(i) = 0;
        }
    }
}

unordered_map<string, int> stats;   // name and its total length of calls
unordered_map<string, int> name2num; // name to its number
vector<pair<string, int> > input; // store the input using one name only
int counter = 0;

int main() {

    int n, k, time;
    scanf("%d %d", &n, &k);
    UnionFindSet::reset();
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", name1, name2, &time);
        if (name2num.find(name1) == name2num.end()) {
            name2num[name1] = counter;
            ++counter;
        }
        if (name2num.find(name2) == name2num.end()) {
            name2num[name2] = counter;
            ++counter;
        }
        stats[name1] += time;
        stats[name2] += time;
        if (UnionFindSet::find(name2num[name1]) !=
            UnionFindSet::find(name2num[name2])) {
            UnionFindSet::merge(name2num[name1], name2num[name2]);
        }
        // store the input
        input.emplace_back(make_pair(name1, time));
    }
    unordered_map<int, vector<string> > groupNumber2groupMember;
    unordered_map<string, int> groupMember2groupNumber;
    for (const auto &it : stats) {
        auto temp = UnionFindSet::find(name2num[it.first]);
        groupNumber2groupMember[temp].emplace_back(it.first);
        groupMember2groupNumber[it.first] = temp;
    }

    unordered_map<int, int> groupNumber2groupTotalRelationWeight;
    for (const auto &it : input) {
        groupNumber2groupTotalRelationWeight[groupMember2groupNumber[it.first]] += it.second;
    }

    vector<pair<string, int> > output;
    for (const auto &it : groupNumber2groupMember) {
        if (it.second.size() > 2 &&
            groupNumber2groupTotalRelationWeight[it.first] > k) {
            output.emplace_back(
                    make_pair(
                            *max_element(it.second.begin(), it.second.end(),
                                         [](const string &lhs,
                                            const string &rhs) {
                                             return (stats[lhs] <
                                                     stats[rhs]);
                                         }),
                            static_cast<int>(it.second.size())));
        }
    }
    sort(output.begin(), output.end(),
         [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
             return (lhs.first < rhs.first);
         });
    // output
    printf("%d\n", static_cast<int>(output.size()));
    for (const auto &i : output) {
        printf("%s %d\n", i.first.c_str(), i.second);
    }

    return 0;
}
