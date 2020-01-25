// https://open.kattis.com/problems/engineeringenglish
#include <bits/extc++.h>

using namespace std;

unordered_set<string> A;

bool noDuplicate(string word) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        }
    }
    if (A.find(word) != A.end()) {
        return false;
    }
    A.insert(word);
    return true;
}

void handle(string s) {
    string word;
    string new_s;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (word != "") {
                if (noDuplicate(word)) {
                    new_s = new_s + word;
                } else {
                    new_s = new_s + ".";
                }
                word = "";
            }
            new_s = new_s + s[i];
        } else {
            word = word + s[i];
        }
    }
    if (word != "") {
        if (noDuplicate(word)) {
            new_s = new_s + word;
        } else {
            new_s = new_s + ".";
        }
    }
    cout << new_s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        handle(s);
    }
    return 0;
}
