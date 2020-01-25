// https://open.kattis.com/problems/empleh
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 8;

vector<vector<char> > chessboard(MAXN, vector<char>(MAXN));

inline static
pair<int, int> convert(char x, int y) {
    pair<int, int> result;
    result.first = (int) (x - 'a');
    result.second = MAXN - y;
    return result;
}

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

inline static
void parse(const string &s, bool isWhite) {
    auto split0 = splitByChar(s, ' ');
    if (split0.size() > 1) {
        auto split1 = splitByChar(split0.at(1), ',');
        char chess;
        int row;
        int col;
        for (const auto &i : split1) {
            // chess
            if (i.size() == 2) {
                if (isWhite) {
                    chess = 'P';
                } else {
                    chess = 'p';
                }
            } else {
                if (isWhite) {
                    chess = (char) toupper(i.at(0));
                } else {
                    chess = (char) tolower(i.at(0));
                }
            }
            if (i.size() == 2) {
                auto p = convert(i.at(0), i.at(1) - '0');
                row = p.first;
                col = p.second;
            } else {
                auto p = convert(i.at(1), i.at(2) - '0');
                row = p.first;
                col = p.second;
            }
            chessboard.at(col).at(row) = chess;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    parse(s, true);
    getline(cin, s);
    parse(s, false);
    bool change;

    for (int i = 0, index = 0; i < 2 * MAXN + 1; ++i) {
        if (i % 2 == 0) {
            cout << "+---+---+---+---+---+---+---+---+" << endl;
        } else {
            if (index % 2 == 0) {
                change = true;
            } else {
                change = false;
            }
            string content;
            for (int j = 0; j < MAXN; ++j) {
                cout << "|";
                if (isalpha(chessboard.at(index).at(j))) {
                    content = chessboard.at(index).at(j);
                } else {
                    if (change) {
                        content = ".";
                    } else {
                        content = ":";
                    }
                }
                if (change) {
                    content = "." + content + ".";
                } else {
                    content = ":" + content + ":";
                }
                change = !change;
                cout << content;
            }
            cout << "|" << endl;
            ++index;
        }
    }

    return 0;
}
