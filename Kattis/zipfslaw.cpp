// https://open.kattis.com/problems/zipfslaw

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <regex>
#include <unordered_map>

using namespace std;
const regex R("[a-zA-Z]+");
const string NOT_EXIST = "There is no such word.";

int main() {

    ios_base::sync_with_stdio(false);

    bool firstCase = true;
    int n;
    string s, paragraph;

    while (cin >> n) {

        unordered_map<string, int> freq;
        paragraph = "";
        if (firstCase) {
            firstCase = false;
        } else {
            cout << endl;
        }
        while (cin >> s) {
            if (s == "EndOfText") {
                break;
            } else {
                paragraph += s + " ";
            }
        }
        for (sregex_iterator it(paragraph.begin(), paragraph.end(), R), end_it; it != end_it; ++it) {
            s = it->str();
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            ++freq[s];
        }
        vector<string> result;
        for (const auto &it : freq) {
            if (it.second == n) {
                result.push_back(it.first);
            }
        }
        sort(result.begin(), result.end());
        if (result.empty()) {
            cout << NOT_EXIST << endl;
        } else {
            for (const auto &i : result) {
                cout << i << endl;
            }
        }
    }

    return 0;
}
