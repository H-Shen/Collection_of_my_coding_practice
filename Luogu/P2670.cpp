#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 105;
char cstr[MAXN];

int main() {

    int r, c;
    scanf("%d %d", &r, &c);
    vector<vector<char> > A;
    string s;
    for (int i = 0; i < r; ++i) {
        scanf("%s", cstr);
        s = cstr;
        A.emplace_back(s.begin(), s.end());
    }
    vector<vector<int> > B(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) == '*') {
                B.at(i).at(j) = '*';
            }
        }
    }
    int counter;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) != '*') {
                counter = 0;
                try { if (A.at(i).at(j+1) == '*') ++counter; } catch (...) {}
                try { if (A.at(i).at(j-1) == '*') ++counter; } catch (...) {}
                try { if (A.at(i+1).at(j+1) == '*') ++counter; } catch (...) {}
                try { if (A.at(i+1).at(j-1) == '*') ++counter; } catch (...) {}
                try { if (A.at(i+1).at(j) == '*') ++counter; } catch (...) {}
                try { if (A.at(i-1).at(j+1) == '*') ++counter; } catch (...) {}
                try { if (A.at(i-1).at(j-1) == '*') ++counter; } catch (...) {}
                try { if (A.at(i-1).at(j) == '*') ++counter; } catch (...) {}
                B.at(i).at(j) = counter + '0';
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%c", B.at(i).at(j));
        }
        printf("\n");
    }

    return 0;
}
