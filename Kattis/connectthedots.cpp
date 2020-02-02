// https://open.kattis.com/problems/connectthedots
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline
unordered_map<char, int> A;

struct Symbol {
    char ch;
    size_t i;
    size_t j;

    explicit Symbol(char ch, size_t i, size_t j) : ch(ch), i(i), j(j) {}
};

inline static
bool cmp_func(const Symbol &lhs, const Symbol &rhs) {
    return A[lhs.ch] < A[rhs.ch];
}

inline static
void pre() {
    string s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = static_cast<int>(s.size());
    for (int i = 0; i < n; ++i) {
        A[s[i]] = i;
    }
}

enum class Direction {
    Down, Up, Left, Right
};

inline static
void connect(vector<vector<char> > &board, size_t i, size_t j, size_t dst_i,
             size_t dst_j) {
    // Confirm the direction
    Direction direction;
    if (i == dst_i) {
        if (j < dst_j) {
            direction = Direction::Right;
        } else {
            direction = Direction::Left;
        }
    } else {
        if (i < dst_i) {
            direction = Direction::Down;
        } else {
            direction = Direction::Up;
        }
    }
    // Start drawing the path
    size_t current_i = i;
    size_t current_j = j;
    switch (direction) {
        case Direction::Up:
            while (!(current_i == dst_i && current_j == dst_j)) {
                if (A.find(board.at(current_i).at(current_j)) == A.end()) {
                    if (board.at(current_i).at(current_j) == '-') {
                        board.at(current_i).at(current_j) = '+';
                    } else if (board.at(current_i).at(current_j) != '+') {
                        board.at(current_i).at(current_j) = '|';
                    }
                }
                --current_i;
            }
            break;
        case Direction::Down:
            while (!(current_i == dst_i && current_j == dst_j)) {
                if (A.find(board.at(current_i).at(current_j)) == A.end()) {
                    if (board.at(current_i).at(current_j) == '-') {
                        board.at(current_i).at(current_j) = '+';
                    } else if (board.at(current_i).at(current_j) != '+') {
                        board.at(current_i).at(current_j) = '|';
                    }
                }
                ++current_i;
            }
            break;
        case Direction::Left:
            while (!(current_i == dst_i && current_j == dst_j)) {
                if (A.find(board.at(current_i).at(current_j)) == A.end()) {
                    if (board.at(current_i).at(current_j) == '|') {
                        board.at(current_i).at(current_j) = '+';
                    } else if (board.at(current_i).at(current_j) != '+') {
                        board.at(current_i).at(current_j) = '-';
                    }
                }
                --current_j;
            }
            break;
        default:
            while (!(current_i == dst_i && current_j == dst_j)) {
                if (A.find(board.at(current_i).at(current_j)) == A.end()) {
                    if (board.at(current_i).at(current_j) == '|') {
                        board.at(current_i).at(current_j) = '+';
                    } else if (board.at(current_i).at(current_j) != '+') {
                        board.at(current_i).at(current_j) = '-';
                    }
                }
                ++current_j;
            }
            break;
    }
}

int main() {

    pre();
    bool firstItem = true;
    bool lastCase = false;

    while (true) {
        string s;
        vector<vector<char> > board;
        while (true) {
            // Last case
            if (!getline(cin, s)) {
                lastCase = true;
                break;
            }
            // Next case
            if (s.empty()) {
                break;
            }
            board.emplace_back(s.begin(), s.end());
        }
        vector<Symbol> symbols;
        for (size_t i = 0; i != board.size(); ++i) {
            for (size_t j = 0; j != board.at(i).size(); ++j) {
                if (board.at(i).at(j) != '.') {
                    symbols.emplace_back(Symbol(board.at(i).at(j), i, j));
                }
            }
        }
        sort(symbols.begin(), symbols.end(), cmp_func);
        int n = static_cast<int>(symbols.size());
        for (int i = 0; i < n - 1; ++i) {
            connect(board, symbols.at(i).i, symbols.at(i).j,
                    symbols.at(i + 1).i, symbols.at(i + 1).j);
        }
        // output
        if (firstItem) {
            firstItem = false;
        } else {
            printf("\n");
        }
        for (const auto &i : board) {
            for (const auto &j : i) {
                printf("%c", j);
            }
            printf("\n");
        }
        if (lastCase) {
            break;
        }
    }
    return 0;
}
