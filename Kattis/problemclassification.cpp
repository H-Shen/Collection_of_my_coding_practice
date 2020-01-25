// https://open.kattis.com/problems/problemclassification
//
#include <bits/extc++.h>

using namespace std;

unordered_map<string, vector<string> > keyword2categoryList;
unordered_map<string, int> categoryOccurrence;
vector<pair<string, int> > result;

// This problem has a trap, if no keywords are found on the text given, we should still print out
// all categories lexicographically.
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string category;
    string keyword;
    int W;
    cin >> N;
    while (N--) {
        cin >> category >> W;
        categoryOccurrence[category] = 0;
        while (W--) {
            cin >> keyword;
            keyword2categoryList[keyword].emplace_back(category);
        }
    }
    string word;
    while (cin >> word) {
        if (keyword2categoryList.find(word) != keyword2categoryList.end()) {
            for (const auto &i : keyword2categoryList[word]) {
                ++categoryOccurrence[i];
            }
        }
    }
    // get result
    result.resize(categoryOccurrence.size());
    auto result_iter = result.begin();
    for (const auto &it : categoryOccurrence) {
        *result_iter = make_pair(it.first, it.second);
        advance(result_iter, 1);
    }
    // sort
    sort(result.begin(), result.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
        return (lhs.first < rhs.first);
    });
    // get max occurrence
    int maxOccurrence = 0;
    for (const auto &i : result) {
        maxOccurrence = max(maxOccurrence, i.second);
    }
    // output
    for (const auto &i : result) {
        if (i.second == maxOccurrence) {
            cout << i.first << '\n';
        }
    }

    return 0;
}
