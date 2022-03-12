// https://open.kattis.com/problems/gandalfsspell

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

string s;

int main() {
    getline(cin, s);
    vector<int> vec;
    int id = 0;
    unordered_map<char,int> unmap;
    for (const auto&i : s) {
        if (unmap.count(i) > 0) {
            vec.emplace_back(unmap[i]);
        } else {
            vec.emplace_back(id);
            unmap[i] = id;
            ++id;
        }
    }
    vector<int> vec2;
    unordered_map<string,int> unmap2;
    id = 0;
    getline(cin, s);
    vector<string> tempVec;
    string temp;
    istringstream iss(s);
    do {
        iss >> temp;
        tempVec.emplace_back(temp);
    } while (iss);
    tempVec.pop_back();
    for (auto& word : tempVec) {
        if (unmap2.count(word) > 0) {
            vec2.emplace_back(unmap2[word]);
        } else {
            vec2.emplace_back(id);
            unmap2[word] = id;
            ++id;
        }
    }
    if (vec == vec2) {
        cout << "True" << '\n';
    } else {
        cout << "False" << '\n';
    }
    return 0;
}
