#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, gender, height, weight;
    cin >> n;
    while (n--) {
        cin >> gender >> height >> weight;
        switch (gender) {
            case 0:
                if (height < 129) {
                    cout << "duo chi yu! ";
                } else if (height == 129) {
                    cout << "wan mei! ";
                } else {
                    cout << "ni li hai! ";
                }
                break;
            case 1:
                if (height < 130) {
                    cout << "duo chi yu! ";
                } else if (height == 130) {
                    cout << "wan mei! ";
                } else {
                    cout << "ni li hai! ";
                }
                break;
            default:
                break;
        }

        switch (gender) {
            case 0:
                if (weight < 25) {
                    cout << "duo chi rou!";
                } else if (weight == 25) {
                    cout << "wan mei!";
                } else {
                    cout << "shao chi rou!";
                }
                break;
            case 1:
                if (weight < 27) {
                    cout << "duo chi rou!";
                } else if (weight == 27) {
                    cout << "wan mei!";
                } else {
                    cout << "shao chi rou!";
                }
                break;
            default:
                break;
        }
        cout << endl;
    }

    return 0;
}