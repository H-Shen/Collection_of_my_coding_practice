// https://open.kattis.com/problems/peasoup
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, item;
    cin >> n;
    string s;
    string name, name_of_item;
    while (n--) {
        cin >> item;
        cin.get();
        getline(cin, name);
        bool hasPeaSoup = false;
        bool hasPanCakes = false;
        while (item--) {
            getline(cin, name_of_item);
            if (name_of_item == "pancakes") {
                hasPanCakes = true;
            } else if (name_of_item == "pea soup") {
                hasPeaSoup = true;
            }
        }
        if (hasPanCakes && hasPeaSoup) {
            if (s.empty()) {
                s = name;
            }
        }
    }
    if (s.empty()) {
        cout << "Anywhere is fine I guess" << '\n';
    } else {
        cout << s << '\n';
    }

    return 0;
}
