// https://open.kattis.com/problems/prerequisites

#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int course, category, c, r, cnt;
    string courseNum;
    bool hasAns = true;

    while (true) {
        hasAns = true;
        cin >> course;
        if (course == 0) {
            break;
        }
        cin >> category;
        unordered_set<string> courseList;
        for (int i = 0; i < course; ++i) {
            cin >> courseNum;
            courseList.insert(courseNum);
        }
        for (int i = 0; i < category; ++i) {
            cnt = 0;
            cin >> c >> r;
            for (int j = 0; j < c; ++j) {
                cin >> courseNum;
                if (courseList.find(courseNum) != courseList.end()) {
                    ++cnt;
                }
            }
            if (cnt < r) {
                hasAns = false;
            }
        }
        if (!hasAns) {
            cout << "no";
        } else {
            cout << "yes";
        }
        cout << endl;
    }
    return 0;
}
