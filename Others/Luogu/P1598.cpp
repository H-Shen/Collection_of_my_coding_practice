#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 26;

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

    vector<int> stats(MAXN);
    char ch;
    while (~scanf("%c", &ch)) {
        if (isupper(ch)) {
            ++stats[ch - 'A'];
        }
    }
    vector<vector<char> > L;
    vector<char> boundary;
    int max_length = -1;
    for (int i = 0; i < MAXN; ++i) {
        string temp = static_cast<char>(i + 'A') + string(stats.at(i), '*');
        L.emplace_back(temp.begin(), temp.end());
        L.emplace_back(boundary);
        max_length = max(max_length, static_cast<int>(temp.size()));
    }
    L.pop_back();

    int length_L = static_cast<int>(L.size());
    for (int i = 0; i < length_L; ++i) {
        int temp_length = static_cast<int>(L.at(i).size());
        while (temp_length < max_length) {
            L.at(i).emplace_back(' ');
            ++temp_length;
        }
    }

    L = matrixRotation(L);
    reverse(L.begin(), L.end());
    for (auto &i : L) {
        while (i.back() == ' ') {
            i.pop_back();
        }
    }
    for (const auto &i : L) {
        string temp(i.begin(), i.end());
        printf("%s\n", temp.c_str());
    }
    return 0;
}
