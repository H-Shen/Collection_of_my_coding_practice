#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Stu {
    string name;
    string gender;
    string id;
    int grade;
};

int main() {

    int n;
    vector<Stu> male;
    vector<Stu> female;
    Stu tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
        if (tmp.gender == "M") {
            male.push_back(tmp);
        } else {
            female.push_back(tmp);
        }
    }
    auto f = [](const Stu &a, const Stu &b) -> bool { return a.grade < b.grade; };
    bool haveAns = true;
    int femaleMaxGrade = 0, maleMinGrade = 0;

    if (female.empty()) {
        cout << "Absent" << endl;
        haveAns = false;
    } else {
        auto res0 = *max_element(female.begin(), female.end(), f);
        cout << res0.name << ' ' << res0.id << endl;
        femaleMaxGrade = res0.grade;
    }

    if (male.empty()) {
        cout << "Absent" << endl;
        haveAns = false;
    } else {
        auto res1 = *min_element(male.begin(), male.end(), f);
        cout << res1.name << ' ' << res1.id << endl;
        maleMinGrade = res1.grade;
    }

    if (haveAns) {
        cout << abs(femaleMaxGrade - maleMinGrade) << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}
