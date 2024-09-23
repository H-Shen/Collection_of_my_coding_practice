// https://www.nowcoder.com/practice/f884ea80bfbf4b14a56313c95541b00e

#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name, sex;
    int age{};
};

int main() {

    ios_base::sync_with_stdio(false);
    int m, n, id;
    cin >> m;
    while (m--) {
        cin >> n;
        unordered_map<int, Student> A;
        while (n--) {
            Student p;
            cin >> id >> p.name >> p.sex >> p.age;
            A[id] = p;
        }
        cin >> id;
        cout << id << ' ' << A[id].name << ' ' << A[id].sex << ' ' << A[id].age << endl;
    }

    return 0;
}