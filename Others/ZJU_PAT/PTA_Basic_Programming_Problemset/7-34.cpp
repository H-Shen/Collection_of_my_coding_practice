#include <iostream>
#include <vector>

using namespace std;

struct Item {
    string name;
    string birth;
    string sex;
    string tel;
    string mobile;
};

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Item> A(static_cast<size_t>(n));
    for (auto &&i : A) {
        cin >> i.name >> i.birth >> i.sex >> i.tel >> i.mobile;
    }
    int m, query;
    cin >> m;
    while (m--) {
        cin >> query;
        if (query < 0 || query >= n) {
            cout << "Not Found";
        } else {
            cout << A[query].name << ' ' << A[query].tel << ' ' << A[query].mobile << ' ' << A[query].sex << ' '
                 << A[query].birth;
        }
        cout << endl;
    }
    return 0;
}