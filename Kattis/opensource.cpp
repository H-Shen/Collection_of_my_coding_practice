// https://open.kattis.com/problems/opensource
//
#include<bits/stdc++.h>

using namespace std;

inline static
bool isUserId(const string &s) {
    if (!islower(s.at(0))) {
        return false;
    }
    for (size_t i = 1; i != s.size(); ++i) {
        if (!islower(s.at(i)) && !isdigit(s.at(i))) {
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string currentProjectName;
    unordered_map<string, unordered_set<string> > project2member;
    unordered_map<string, unordered_set<string> > member2project;
    vector<string> temp;
    vector<pair<string, int> > output;
    while (true) {
        getline(cin, s);
        if (s == "0") {
            break;
        }
        if (s.front() == '1') {
            // filter those students who commit more than 1 project
            for (const auto &i : member2project) {
                if (i.second.size() > 1) {
                    temp.emplace_back(i.first);
                }
            }
            for (const auto &i : temp) {
                for (auto &j : project2member) {
                    if (j.second.find(i) != j.second.end()) {
                        j.second.erase(i);
                    }
                }
            }
            // stats
            for (const auto &i : project2member) {
                output.emplace_back(make_pair(i.first, static_cast<int>(i.second.size())));
            }
            // sort
            sort(output.begin(), output.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
                if (lhs.second == rhs.second) {
                    return (lhs.first < rhs.first);
                }
                return (lhs.second > rhs.second);
            });
            // output
            for (const auto& [k, v] : output) {
                cout << k << ' ' << v << '\n';
            }
            // clean
            project2member.clear();
            member2project.clear();
            vector<string>().swap(temp);
            vector<pair<string, int> >().swap(output);
        } else if (isUserId(s)) {
            project2member[currentProjectName].insert(s);
            member2project[s].insert(currentProjectName);
        } else {
            currentProjectName = s;
            project2member[s];
        }
    }

    return 0;
}
