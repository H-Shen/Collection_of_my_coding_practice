#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 100;

vector<vector<pair<bool, string>>> A(maxn);

int main() {

    ios_base::sync_with_stdio(false);

    int t, tempVal;
    string tempStr;

    cin >> t;
    int halfPos = t / 2;
    int currentPos = 1;
    int maxVal = -1;
    while (t--) {
        cin >> tempVal >> tempStr;

        if (tempVal > maxVal)
            maxVal = tempVal;

        pair<bool, string> tempPair = {false, tempStr};

        if (currentPos > halfPos)
            tempPair.first = true;

        A[tempVal].push_back(tempPair);
        currentPos++;
    }

    int i, j, len;
    for (i = 0; i < maxVal + 1; i++) {
        len = A[i].size();
        for (j = 0; j < len; j++) {
            if (i == maxVal && j == len - 1) {
                if (A[i][j].first == false)
                    cout << "- ";
                else
                    cout << A[i][j].second << ' ';
            }
            else {
                if (A[i][j].first == false)
                    cout << "- ";
                else
                    cout << A[i][j].second << ' ';
            }
        }
    }

    return 0;
}
