#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int n;
    cin >> n;
    string name;
    int age;
    int grade;
    int temp;
    while (n--) {
        cin >> name >> age >> grade;
        temp = (grade + grade / 5);
        if (temp > 600) {
            temp = 600;
        }
        cout << name << ' ' << (age + 1) << ' ' << temp << endl;
    }
    return 0;
}
