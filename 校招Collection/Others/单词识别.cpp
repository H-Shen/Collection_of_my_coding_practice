// https://www.nowcoder.com/practice/16f59b169d904f8898d70d81d4a140a0

#include <iostream>
#include <unordered_map>
#include <regex>
#include <string>

using namespace std;

const string pattern("[^ ,.]+");
const regex r(pattern);

int main() {

    string s, temp;
    unordered_map<string, int> A;
    while (cin >> s) {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
            temp = it->str();
            transform(cbegin(temp), cend(temp), begin(temp), ::tolower);
            ++A[temp];
        }
    }
    vector<pair<string, int> > result(A.size());
    auto iter = A.cbegin();
    for (size_t i = 0; i != result.size(); ++i) {
        result.at(i) = make_pair(iter->first, iter->second);
        ++iter;
    }
    sort(result.begin(), result.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return (a.first < b.first);
    });
    for (const auto &it : result) {
        cout << it.first << ":" << it.second << endl;
    }
    return 0;
}