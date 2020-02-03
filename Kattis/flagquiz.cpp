// https://open.kattis.com/problems/flagquiz
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Answer {
    string s;
    vector<string> p;
    int index;
};

bool cmp_func(const Answer &lhs, const Answer &rhs) {
    return (lhs.index < rhs.index);
}

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    cin.get();
    vector<Answer> A(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, A.at(i).s);
        A.at(i).p = splitByChar(A.at(i).s, ',');
        A.at(i).index = i;
    }
    if (n == 1) {
        cout << A.front().s << '\n';
    } else {
        int smallest = numeric_limits<int>::max();
        int counter;
        int temp;
        for (int i = 0; i < n; ++i) {
            counter = 0;
            for (int j = 0; j < n; ++j) {
                temp = 0;
                for (size_t k = 0; k != A.at(i).p.size(); ++k) {
                    if (A.at(i).p.at(k) != A.at(j).p.at(k)) {
                        ++temp;
                    }
                }
                counter = max(counter, temp);   // get incongruousity: maximum number of changes needed
            }
            smallest = min(counter, smallest);  // get the smallest incongruousity
        }
        // output
        vector<Answer> output;
        for (int i = 0; i < n; ++i) {
            counter = 0;
            for (int j = 0; j < n; ++j) {
                temp = 0;
                for (size_t k = 0; k != A.at(i).p.size(); ++k) {
                    if (A.at(i).p.at(k) != A.at(j).p.at(k)) {
                        ++temp;
                    }
                }
                counter = max(counter, temp);
            }
            if (counter == smallest) {
                output.emplace_back(A.at(i));
            }
        }
        sort(output.begin(), output.end(), cmp_func);
        for (const auto &i : output) {
            cout << i.s << '\n';
        }
    }

    return 0;
}
