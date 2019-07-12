// https://www.nowcoder.com/practice/24575008c6134b6fa4fab8ea0ea82a99

#include <iostream>
#include <string>

using namespace std;

string repeat(string x, int k) {
    string result;
    for (int i = 0; i < k; ++i) {
        result += x;
    }
    return result;
}


int main() {

    ios_base::sync_with_stdio(false);
    string v1, v2, x1, x2;
    int k1, k2;
    cin >> x1 >> k1 >> x2 >> k2;

    v1 = repeat(x1, k1);
    v2 = repeat(x2, k2);

    if (v1.size() > v2.size()) {
        cout << "Greater";
    } else if (v1.size() < v2.size()) {
        cout << "Less";
    } else {
        int comp = v1.compare(v2);
        if (comp == 0) {
            cout << "Equal";
        } else if (comp > 0) {
            cout << "Greater";
        } else {
            cout << "Less";
        }
    }
    cout << endl;


    return 0;
}