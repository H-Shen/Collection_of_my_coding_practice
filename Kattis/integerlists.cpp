// https://open.kattis.com/problems/integerlists
//
#include <bits/extc++.h>

using namespace std;

inline static
void purseInput(deque<string> &A, const string &s, const int &n) {
    if (n != 0) {
        string number;
        A.resize(n);
        size_t index = 0;
        for (size_t i = 1; i < s.size() - 1; ++i) {
            if (isdigit(s[i])) {
                number.push_back(s[i]);
            } else {
                A[index++] = number;
                number.clear();
            }
        }
        A[index] = number;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    int T, n;
    bool isReversed;
    bool hasError;
    bool firstItem;
    string p, s;
    cin >> T;
    while (T--) {
        cin >> p >> n >> s;
        deque<string> A;
        purseInput(A, s, n);
        isReversed = false;
        hasError = false;
        for (const char &ch : p) {
            if (ch == 'R') {
                isReversed = !isReversed;
            } else {
                if (isReversed) {
                    if (!A.empty()) {
                        A.pop_back();
                    } else {
                        hasError = true;
                        break;
                    }
                } else {
                    if (!A.empty()) {
                        A.pop_front();
                    } else {
                        hasError = true;
                        break;
                    }
                }
            }
        }

        // output
        if (hasError) {
            cout << "error" << endl;
        } else {
            firstItem = true;
            cout << "[";
            if (!isReversed) {
                for (const string &i : A) {
                    if (firstItem) {
                        firstItem = false;
                    } else {
                        cout << ',';
                    }
                    cout << i;
                }
            } else {
                for (auto it = A.crbegin(); it != A.crend(); ++it) {
                    if (firstItem) {
                        firstItem = false;
                    } else {
                        cout << ',';
                    }
                    cout << *it;
                }
            }
            cout << "]" << endl;
        }

    }

    return 0;
}
