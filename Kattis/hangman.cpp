// https://open.kattis.com/problems/hangman
#include <iostream>
#include <string>

using namespace std;
const int MAX_CHANCES = 10;
const char CORRENT_ANSWER = 'a';

bool allCorrect(const string &s) {
    for (const auto & ch : s) {
        if (ch != 'a') {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);

    string word, perm;
    bool hasAns;
    int chances = MAX_CHANCES;
    cin >> word >> perm;

    for (const auto & ch : perm) {
        hasAns = false;
        for (size_t i = 0; i != word.size(); ++i) {
            if (word[i] == ch) {
                word[i] = CORRENT_ANSWER;
                hasAns = true;
            }
        }
        if (allCorrect(word)) {
            cout << "WIN" << endl;
            return 0;
        }
        if (!hasAns) {
            --chances;
            if (chances == 0) {
                cout << "LOSE" << endl;
                return 0;
            }
        }
    }
}
