#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
vector<vector<char> > rotateRight(const vector<vector<char> > &s) {
    if (s.empty() || s.front().empty()) {
        return vector<vector<char> >();
    }
    vector<vector<char> > result(s.front().size(), vector<char>(s.size()));
    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result.at(i).size(); ++j) {
            result.at(i).at(j) = s.at(s.size() - 1 - j).at(i);
        }
    }
    return result;
}

inline static
vector<vector<char> > rotateLeft(const vector<vector<char> > &s) {
    return rotateRight(rotateRight(rotateRight(s)));
}

int main() {

    int r, c, z_r, z_c;
    cin >> r >> c >> z_r >> z_c;
    vector<vector<char> > A;

    // input
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        A.emplace_back(s.begin(), s.end());
    }

    // increase along rows
    vector<vector<char> > output;
    for (int i = 0; i < r; ++i) {
        vector<char> temp;
        for (int j = 0; j < c; ++j) {
            for (int counter = 0; counter < z_c; ++counter) {
                temp.emplace_back(A.at(i).at(j));
            }
        }
        output.emplace_back(temp);
    }

    output = rotateRight(output);

    // increase along cols
    vector<vector<char> > output2;
    int r_output = static_cast<int>(output.size());
    int c_output = static_cast<int>(output.front().size());
    for (int i = 0; i < r_output; ++i) {
        vector<char> temp;
        for (int j = 0; j < c_output; ++j) {
            for (int counter = 0; counter < z_r; ++counter) {
                temp.emplace_back(output.at(i).at(j));
            }
        }
        output2.emplace_back(temp);
    }
    output2 = rotateLeft(output2);

    // output
    for (const auto &i : output2) {
        for (const auto &j : i) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}
