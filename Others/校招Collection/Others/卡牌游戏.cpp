// https://ac.nowcoder.com/acm/problem/14715

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int alice = 0, bob = 0;
    string a, b;
    while (n--) {
        cin >> a >> b;
        if (a == "Jin") {
            if (b == "Jin" || b == "Shui" || b == "Tu") {
                ++alice;
                ++bob;
            }
            else if (b == "Mu") {
                alice += 3;
            }
            else if (b == "Huo") {
                bob += 3;
            }
        }
        else if (a == "Mu") {
            if (b == "Mu" || b == "Shui" || b == "Huo") {
                ++alice;
                ++bob;
            }
            else if (b == "Tu") {
                alice += 3;
            }
            else if (b == "Jin") {
                bob += 3;
            }
        }
        else if (a == "Shui") {
            if (b == "Shui" || b == "Jin" || b == "Mu") {
                ++alice;
                ++bob;
            }
            else if (b == "Huo") {
                alice += 3;
            }
            else if (b == "Tu") {
                bob += 3;
            }
        }
        else if (a == "Huo") {
            if (b == "Huo" || b == "Tu" || b == "Mu") {
                ++alice;
                ++bob;
            }
            else if (b == "Jin") {
                alice += 3;
            }
            else if (b == "Shui") {
                bob += 3;
            }
        }
        else if (a == "Tu") {
            if (b == "Tu" || b == "Jin" || b == "Huo") {
                ++alice;
                ++bob;
            }
            else if (b == "Shui") {
                alice += 3;
            }
            else if (b == "Mu") {
                bob += 3;
            }
        }
    }
    if (alice == bob) cout << "Draw" << endl;
    else if (alice > bob) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}