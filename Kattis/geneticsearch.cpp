// https://open.kattis.com/problems/geneticsearch
//
#include <bits/stdc++.h>

using namespace std;

constexpr int maxLength = 105;
char patternCStr[maxLength];
char textCStr[maxLength];

inline static
char GeneticList[] = {'A', 'C', 'G', 'T'};

template<class T>
int KMP(T const &Text, T const &Pattern) {

    vector<int> b(Pattern.size() + 1, -1);
    int matches = 0;

    // Preprocess
    for (size_t i = 1; i <= Pattern.size(); i++) {
        int pos = b[i - 1];
        while (pos != -1 && Pattern[pos] != Pattern[i - 1])
            pos = b[pos];
        b[i] = pos + 1;
    }

    // Search
    int sp = 0, kp = 0;
    while (sp < Text.size()) {
        while (kp != -1 && (kp == Pattern.size() || Pattern[kp] != Text[sp])) {
            kp = b[kp];
        }
        ++kp;
        ++sp;
        if (kp == Pattern.size()) {
            ++matches;
        }
    }
    return matches;
}

inline static
unordered_set<string> allUniqStrAfterDeleteOneCharacter(const string &s) {
    unordered_set<string> A;
    for (size_t i = 0; i != s.size(); ++i) {
        string temp;
        for (size_t j = 0; j != s.size(); ++j) {
            if (i != j) {
                temp.push_back(s.at(j));
            }
        }
        A.insert(temp);
    }
    return A;
}

inline static
unordered_set<string> allUniqStrAfterAddOneCharacter(const string &s) {

    unordered_set<string> A;
    vector<char> L(2 * s.size() + 1);

    for (size_t i = 0, j = 0; i != L.size(); ++i) {
        if (i % 2 == 0) {
            L.at(i) = '\0';
        } else {
            L.at(i) = s.at(j);
            ++j;
        }
    }

    int index;
    string tempStr;
    for (size_t i = 0; i != L.size(); ++i) {
        if (L.at(i) == '\0') {
            for (index = 0; index < 4; ++index) {
                L.at(i) = GeneticList[index];
                // get a copy of it
                tempStr = "";
                for (size_t j = 0; j != L.size(); ++j) {
                    if (L.at(j) != '\0') {
                        tempStr.push_back(L.at(j));
                    }
                }
                // store in the set
                A.insert(tempStr);
            }
            // restore the state
            L.at(i) = '\0';
        }
    }
    return A;
}

int main() {

    string pattern, text;
    int a, b, c;

    while (true) {

        scanf("%s", patternCStr);
        if (strcmp(patternCStr, "0") == 0) {
            break;
        }
        scanf("%s", textCStr);
        pattern = patternCStr;
        text = textCStr;

        // Type 1
        a = KMP<string>(text, pattern);
        // Type 2
        b = 0;
        auto tempSet0 = allUniqStrAfterDeleteOneCharacter(pattern);
        for (const auto &i : tempSet0) {
            b += KMP<string>(text, i);
        }
        // Type 3
        c = 0;
        auto tempSet1 = allUniqStrAfterAddOneCharacter(pattern);
        for (const auto &i : tempSet1) {
            c += KMP<string>(text, i);
        }

        // print
        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}
