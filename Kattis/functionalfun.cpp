// https://open.kattis.com/problems/functionalfun
//
#include <bits/extc++.h>

using namespace std;

inline static
vector<string> parse(const string &s) {
    vector<string> ret;
    string temp;
    istringstream iss(s);
    do {
        iss >> temp;
        ret.emplace_back(temp);
    } while (iss);
    ret.pop_back();
    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n;
    vector<string> temp;
    bool surjective;
    bool injective;
    bool isAFunction;

    while (true) {

        // domain
        if (!getline(cin, s)) {
            break;
        }

        // codomain
        getline(cin, s);
        temp = parse(s);
        unordered_set<string> codomain;
        for (size_t i = 1; i != temp.size(); ++i) {
            codomain.insert(temp.at(i));
        }

        // relation
        unordered_map<string, unordered_set<string> > codomain2domain;
        unordered_map<string, unordered_set<string> > domain2codomain;
        cin >> n;
        cin.get();
        while (n--) {
            getline(cin, s);
            temp = parse(s);
            domain2codomain[temp.at(0)].insert(temp.at(2));
            codomain2domain[temp.at(2)].insert(temp.at(0));
        }

        // check
        isAFunction = true;
        for (const auto &i : domain2codomain) {
            if (i.second.size() > 1) {
                isAFunction = false;
                break;
            }
        }
        surjective = false;
        injective = true;
        if (isAFunction) {
            if (codomain2domain.size() == codomain.size()) {
                surjective = true;
            }
            for (const auto &i : codomain2domain) {
                if (i.second.size() > 1) {
                    injective = false;
                    break;
                }
            }
        }

        // output
        if (!isAFunction) {
            cout << "not a function" << '\n';
        } else if (surjective && injective) {
            cout << "bijective" << '\n';
        } else if (surjective) {
            cout << "surjective" << '\n';
        } else if (injective) {
            cout << "injective" << '\n';
        } else {
            cout << "neither injective nor surjective" << '\n';
        }

    }
    return 0;
}
