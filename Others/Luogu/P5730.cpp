#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
std::vector<std::string> splitByChar(std::string s, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(s);
    std::string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

template<typename T>
inline static
std::vector<std::vector<T> > matrixRotation(const std::vector<std::vector<T> > &A) {
    // Case 1:
    if (A.empty() || A.front().empty()) {
        return std::vector<std::vector<T> >();
    }
    // Case 2:
    std::vector<std::vector<T> > result(A.front().size(), std::vector<T>(A.size()));
    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result.at(i).size(); ++j) {
            result.at(i).at(j) = A.at(j).at(i);
        }
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX\n"
               "X.X...X...X...X.X.X.X...X.....X.X.X.X.X\n"
               "X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX\n"
               "X.X...X.X.....X...X...X.X.X...X.X.X...X\n"
               "XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX";

    auto p = splitByChar(s, '\n');
    vector<vector<char> > A;
    for (const auto &i : p) {
        A.emplace_back(i.begin(), i.end());
    }
    A = matrixRotation<char>(A);
    vector<char> temp = {'.','.','.','.','.'};
    vector<vector<char> > B;
    unordered_set<int> pppp = {3, 7, 11, 15, 19, 23, 27, 31, 35};
    for (int i = 0; i < static_cast<int>(A.size()); ++i) {
        if (pppp.find(i) == pppp.end()) {
            B.emplace_back(A.at(i));
        }
    }
    A = B;
    int counter = 0;
    unordered_map<int, vector<vector<char> > > umap;
    vector<vector<char> > temp_vec;
    int key = 0;
    for (auto &i : A) {
        ++counter;
        temp_vec.emplace_back(i.begin(), i.end());
        if (counter == 3) {
            umap[key] = temp_vec;
            vector<vector<char> >().swap(temp_vec);
            ++key;
            counter = 0;
        }
    }

    int length;
    cin >> length;
    string str;
    cin >> s;
    vector<vector<char> > output;
    bool firstItem = true;
    for (const auto &i : s) {
        if (firstItem) {
            firstItem = false;
        } else {
            output.emplace_back(temp);
        }
        auto pp = umap[i - '0'];
        for (auto &j : pp) {
            output.emplace_back(j);
        }
    }
    output = matrixRotation(output);
    for (const auto &i : output) {
        for (const auto &j : i) {
            cout << j;
        }
        cout << '\n';
    }
    return 0;
}