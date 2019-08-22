// https://open.kattis.com/problems/imageprocessing

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
inline static
string matrixToString(const vector<vector<T> > &C) {

    string result;
    if (!C.empty()) {
        size_t row = C.size();
        size_t col = C.at(0).size();
        bool firstItem;
        for (size_t i = 0; i != row; ++i) {
            firstItem = true;
            for (size_t j = 0; j != col; ++j) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    result.push_back(' ');
                }
                result.append(to_string(C.at(i).at(j)));
            }
            if (i != row - 1) {
                result.push_back('\n');
            }
        }
    }
    return result;
}

inline static
void reverseKernel(vector<vector<ll> > &A) {
    for (auto &&i : A) {
        reverse(begin(i), end(i));
    }
    reverse(begin(A), end(A));
}

int main() {

    int H, W, N, M;
    scanf("%d %d %d %d", &H, &W, &N, &M);
    vector<vector<ll> > Image(H, vector<ll>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            scanf("%lld", &Image.at(i).at(j));
        }
    }
    vector<vector<ll> > Kernel(N, vector<ll>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%lld", &Kernel.at(i).at(j));
        }
    }
    reverseKernel(Kernel);

    vector<vector<ll> > Result(H + 1 - N, vector<ll>(W + 1 - M));
    for (int i = 0; i < H + 1 - N; ++i) {
        for (int j = 0; j < W + 1 - M; ++j) {
            for (int m = 0; m < N; ++m) {
                for (int n = 0; n < M; ++n) {
                    Result.at(i).at(j) = Result.at(i).at(j) + Kernel.at(m).at(n) * Image.at(i + m).at(j + n);
                }
            }
        }
    }
    printf("%s", matrixToString(Result).c_str());
    return 0;
}

