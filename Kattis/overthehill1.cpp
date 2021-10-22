// https://open.kattis.com/problems/overthehill1

#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

constexpr int MOD = 37;

template<typename T>
inline static
std::vector<std::vector<T> >
matrixMulMod(const std::vector<std::vector<T> > &A,
             const std::vector<std::vector<T> > &B, const T &mod) {

    // Case 1:
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() ||
        A.at(0).size() != B.size()) {
        throw std::out_of_range("");
    }
    // Case 2:
    std::vector<std::vector<T> > C(A.size(), std::vector<T>(B.at(0).size()));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != B.at(0).size(); ++j) {
            for (size_t k = 0; k != A.at(0).size(); ++k) {
                C.at(i).at(j) =
                        C.at(i).at(j) + A.at(i).at(k) * B.at(k).at(j) % mod;
            }
            C.at(i).at(j) %= mod;
        }
    }
    return C;
}

int n;
vector<vector<int>> A;
unordered_map<char,int> unmap;
vector<char> rev_unmap;

void pre() {
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    for (size_t i = 0; i != s.size(); ++i) {
        unmap[s[i]] = (int)i;
        rev_unmap.emplace_back(s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pre();
    cin >> n;
    A.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    cin.get();
    string s;
    getline(cin, s);
    vector<int> vec;
    for (auto &i : s) {
        vec.emplace_back(unmap[i]);
    }
    while ((int)vec.size() % n != 0) {
        vec.emplace_back(unmap[' ']);
    }
    int length = (int)vec.size();
    vector<vector<int>> B(n, vector<int>(1));
    string ans;
    for (int i = 0; i < length; i += n) {
        for (int j = 0; j < n; ++j) {
            B[j][0] = vec[i+j];
        }
        auto C = matrixMulMod(A, B, MOD);
        for (int j = 0; j < n; ++j) {
            ans.push_back(rev_unmap[C[j][0]]);
        }
    }
    cout << ans << '\n';
    return 0;
}
