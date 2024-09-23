// https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1

#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int grade;
    size_t index;
};

int main() {

    ios_base::sync_with_stdio(false);
    size_t n;
    int a;

    auto cmp0 = [](const Student &lhs, const Student &rhs) -> bool {
        if (lhs.grade == rhs.grade) {
            return (lhs.index < rhs.index);
        }
        return (lhs.grade < rhs.grade);
    };

    auto cmp1 = [](const Student &lhs, const Student &rhs) -> bool {
        if (lhs.grade == rhs.grade) {
            return (lhs.index < rhs.index);
        }
        return (lhs.grade > rhs.grade);
    };

    while (cin >> n) {
        cin >> a;
        vector<Student> table(n);
        for (size_t i = 0; i != n; ++i) {
            cin >> table.at(i).name >> table.at(i).grade;
            table.at(i).index = i;
        }

        if (a == 1) {
            sort(table.begin(), table.end(), cmp0);
        } else {
            sort(table.begin(), table.end(), cmp1);
        }

        for (const auto &i : table) {
            cout << i.name << ' ' << i.grade << endl;
        }
    }

    return 0;
}
