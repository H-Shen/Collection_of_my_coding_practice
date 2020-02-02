// https://open.kattis.com/problems/dyslectionary
//
#include <bits/extc++.h>

using namespace std;

bool cmp(const pair<string, string> &lhs, const pair<string, string> &rhs) {
    return (lhs.second < rhs.second);
}

int main() {

    string s;
    string s_rev;
    vector<pair<string, string> > A;
    bool firstItem = true;
    bool lastCase = false;
    while (true) {
        if (!getline(cin, s)) {
            lastCase = true;
        }
        if (s.empty() || lastCase) {
            // process
            sort(A.begin(), A.end(), cmp);
            // output
            if (firstItem) {
                firstItem = false;
            } else {
                printf("\n");
            }
            int max_length = -1;
            int left_pad;
            for (const auto &i : A) {
                max_length = max(max_length, static_cast<int>(i.first.size()));
            }
            for (const auto &i : A) {
                left_pad = max_length - static_cast<int>(i.first.size());
                for (int pad = 0; pad < left_pad; ++pad) {
                    printf(" ");
                }
                printf("%s\n", i.first.c_str());
            }
            // clean
            vector<pair<string, string> >().swap(A);
        } else {
            s_rev = s;
            reverse(s_rev.begin(), s_rev.end());
            A.emplace_back(s, s_rev);
        }
        if (lastCase) {
            break;
        }
    }

    return 0;
}
