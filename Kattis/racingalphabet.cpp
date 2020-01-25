// https://open.kattis.com/problems/racingalphabet
//
#include <bits/extc++.h>

using namespace std;

unordered_map<char, int> A;

int minimalDistance(char a, char b) {
    int d1 = abs(A[a] - A[b]);
    int d2 = 28 - abs(A[a] - A[b]);
    return min(d1, d2);
}

int main() {

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        A[ch] = (ch - 'A') + 2;
    }
    A[' '] = 0;
    A['\''] = 1;

    int n;
    cin >> n;
    cin.get();
    while (n--) {

        string s;
        getline(cin, s);
        int distance = 0;
        int time = 0;
        int length = static_cast<int>(s.size());
        for (int i = 0; i < length - 1; ++i) {
            distance += minimalDistance(s[i], s[i + 1]);
            ++time;
        }
        ++time;
        double D = M_PI * 60.0 / 28 * distance;
        double T = time * 1.0 + D / 15.0;
        printf("%.10lf\n", T);
    }


    return 0;
}
