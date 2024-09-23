#include <bits/stdc++.h>

using namespace std;

constexpr int judge = 3;

struct A {
    int audience;
    int judge = 0;
    string name;

    A(const string &name_val) : name(name_val) {}

    A() {}

    A(const A &obj) : audience(obj.audience), judge(obj.judge), name(obj.name) {}

    ~A() {}

    A operator=(const A &obj) const {
        A res(obj);
        return res;
    }
};

bool cmp(const A &a, const A &b) {
    return !((a.audience > b.audience && a.judge > 0) || (a.audience < b.audience && a.judge == judge));
}

int main() {

    A a("a"), b("b");
    int tmp;
    cin >> a.audience >> b.audience;

    for (int i = 0; i < judge; ++i) {
        cin >> tmp;
        if (tmp == 0) {
            ++a.judge;
        } else {
            ++b.judge;
        }
    }

    auto res = max(a, b, cmp);
    cout << "The winner is " << res.name << ": " << res.audience << " + " << res.judge << endl;

    return 0;

}
