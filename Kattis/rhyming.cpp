// https://open.kattis.com/problems/rhyming
//
#include <bits/extc++.h>

using namespace std;

unordered_set<string> parse(const string &s) {
    unordered_set<string> res;
    istringstream iss(s);
    string temp;
    do {
        iss >> temp;
        res.insert(temp);
    } while (iss);
    return res;
}

string getLast(const string &s) {
    istringstream iss(s);
    string temp;
    do {
        iss >> temp;
    } while (iss);
    return temp;
}

int main() {

    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    vector<string> A(str.size());
    for (size_t i = 0; i != str.size(); ++i) {
        A.at(i) = str.substr(i);
    }
    int e;
    cin >> e;
    cin.get();
    unordered_set<string> sameWordEndings;
    while (e--) {
        getline(cin, str);
        auto temp = parse(str);
        for (const auto &i : A) {
            if (temp.find(i) != temp.end()) {
                // update sameWordEndings
                for (const auto &j : temp) {
                    sameWordEndings.insert(j);
                }
            }
        }
    }

    int p;
    cin >> p;
    cin.get();
    while (p--) {
        getline(cin, str);
        auto temp = getLast(str);
        bool haveAns = false;
        for (size_t i = 0; i != temp.size(); ++i) {
            if (sameWordEndings.find(temp.substr(i)) != sameWordEndings.end()) {
                haveAns = true;
                break;
            }
        }
        if (haveAns) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }


    return 0;
}
