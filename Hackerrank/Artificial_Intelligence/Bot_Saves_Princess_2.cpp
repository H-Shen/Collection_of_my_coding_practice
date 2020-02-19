#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<char> > A(n, vector<char>(n));
    int m_i, m_j, p_i, p_j;
    cin >> m_i >> m_j;
    cin.get();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A.at(i).at(j);
            if (A.at(i).at(j) == 'p') {
                p_i = i;
                p_j = j;
            }
        }
        cin.get();
    }
    int dist_i = p_i - m_i;
    int dist_j = p_j - m_j;
    if (dist_i == 0 && dist_j == 0) {
        return 0;
    }
    if (dist_i == 0) {
        if (dist_j > 0) {
            cout << "RIGHT" << endl;
        } else {
            cout << "LEFT" << endl;
        }
    } else if (dist_j == 0) {
        if (dist_i > 0) {
            cout << "DOWN" << endl;
        } else {
            cout << "UP" << endl;
        }
    } else {
        if (abs(dist_i) > abs(dist_j)) {
            if (dist_j > 0) {
                cout << "RIGHT" << endl;
            } else {
                cout << "LEFT" << endl;
            }
        } else {
            if (dist_i > 0) {
                cout << "DOWN" << endl;
            } else {
                cout << "UP" << endl;
            }
        }
    }

    return 0;
}