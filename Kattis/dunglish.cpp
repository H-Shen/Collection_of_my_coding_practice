// https://open.kattis.com/problems/dunglish
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Word {
    ll correct = 0;
    ll incorrect = 0;
    vector<string> correctList;
    vector<string> incorrectList;
};

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    vector<string> originalSentence;
    unordered_map<string, Word> stats;

    while (n--) {
        cin >> s;
        originalSentence.emplace_back(s);
    }
    int m;
    cin >> m;
    string original, translation, status;
    while (m--) {
        cin >> original >> translation >> status;
        if (status == "correct") {
            stats[original].correctList.emplace_back(translation);
            ++stats[original].correct;
        } else {
            stats[original].incorrectList.emplace_back(translation);
            ++stats[original].incorrect;
        }
    }

    ll totalCombination = 1;
    ll correctCombination = 1;
    for (const auto &word : originalSentence) {
        correctCombination *= stats[word].correct;
        totalCombination *= (stats[word].correct + stats[word].incorrect);
    }

    // Case 1: only one combination for translation
    if (totalCombination == 1) {
        bool isCorrect = true;
        for (auto &word : originalSentence) {
            if (stats[word].correct == 1) {
                word = stats[word].correctList.front();
            } else {
                isCorrect = false;
                word = stats[word].incorrectList.front();
            }
        }
        // output the translated sentence
        bool firstWord = true;
        for (const auto &word : originalSentence) {
            if (firstWord) {
                firstWord = false;
            } else {
                cout << " ";
            }
            cout << word;
        }
        cout << endl;
        if (isCorrect) {
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }

    // Case 2: multiple combinations for translation, we need to do the stats
    else {
        cout << correctCombination << " correct" << endl;
        cout << totalCombination - correctCombination << " incorrect" << endl;
    }

    return 0;
}
