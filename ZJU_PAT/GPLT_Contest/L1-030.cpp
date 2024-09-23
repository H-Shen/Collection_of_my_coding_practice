#include <bits/stdc++.h>

using namespace std;

struct Stu {

    int id;
    int sex;
    string name;

    Stu() {};

    Stu(int a, int b, string c) : id(a), sex(b), name(c) {};
};

bool cmp(const pair<Stu, Stu> &a, const pair<Stu, Stu> &b) {
    return (a.first.id < b.first.id);
}

int main() {

    list<Stu> List;
    int n, sex, i;
    string name;
    cin >> n;

    for (i = 1; i <= n; ++i) {
        cin >> sex >> name;
        Stu tmp(i, sex, name);
        List.push_back(tmp);
    }

    vector<pair<Stu, Stu> > pairList;

    while (!List.empty()) {

        pair<Stu, Stu> tmpPair;
        auto it = List.begin();
        auto end_it = List.end();
        --end_it;
        while (end_it->sex == it->sex) {
            --end_it;
        }

        tmpPair.first = *it;
        tmpPair.second = *end_it;

        if (tmpPair.first.id > tmpPair.second.id) {
            swap(tmpPair.first, tmpPair.second);
        }
        pairList.push_back(tmpPair);

        List.erase(it);
        List.erase(end_it);
    }

    sort(pairList.begin(), pairList.end(), cmp);

    for (auto &p : pairList) {
        cout << p.first.name << ' ' << p.second.name << endl;
    }

    return 0;
}