// https://open.kattis.com/problems/boundingrobots
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int w;
    int l;
    int n;
    string direction;
    int distance;

    while (true) {
        cin >> w >> l;
        if (w == 0 && l == 0) {
            break;
        }
        cin >> n;
        pair robot_think = {0, 0};
        pair actually = {0, 0};
        while (n--) {
            cin >> direction >> distance;
            if (direction == "u") {
                robot_think.second += distance;
                while (distance--) {
                    if (actually.second < l - 1) {
                        ++actually.second;
                    }
                }
            } else if (direction == "d") {
                robot_think.second -= distance;
                while (distance--) {
                    if (actually.second > 0) {
                        --actually.second;
                    }
                }
            } else if (direction == "l") {
                robot_think.first -= distance;
                while (distance--) {
                    if (actually.first > 0) {
                        --actually.first;
                    }
                }
            } else {
                robot_think.first += distance;
                while (distance--) {
                    if (actually.first < w - 1) {
                        ++actually.first;
                    }
                }
            }
        }
        cout << "Robot thinks " << robot_think.first << ' '
             << robot_think.second << endl;
        cout << "Actually at " << actually.first << ' ' << actually.second
             << endl;
        cout << endl;
    }

    return 0;
}
