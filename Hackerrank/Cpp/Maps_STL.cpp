#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> score;

int main() {
    int T, query, mark;
    string n;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> query >> n;
        switch (query) {
            case 2:
                if (score.find(n) != score.end())
                    score.erase(n);
                break;
            case 3:
                if (score.find(n) != score.end())
                    cout << score[n] << endl;
                else
                    cout << 0 << endl;
                break;
            default:
                cin >> mark;
                score[n] += mark;
                break;
        }
    }
    return 0;
}
