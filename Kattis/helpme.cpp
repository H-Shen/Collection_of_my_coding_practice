// https://open.kattis.com/problems/helpme
//
#include <bits/extc++.h>

using namespace std;

unordered_map<char, int> orderOfType = {
        {'k', 5},
        {'q', 4},
        {'r', 3},
        {'b', 2},
        {'n', 1},
        {'p', 0}
};

struct Chess {
    char chess;
    char x;
    int y;

    explicit Chess(char chess, char x, int y) : chess(chess), x(x), y(y) {}

    [[nodiscard]] string toString() const {
        string output;
        if (chess != 'P' && chess != 'p') {
            output.push_back(toupper(chess));
        }
        output.push_back(x);
        output.append(to_string(y));
        return output;
    }
};

bool cmpFunc(const Chess &lhs, const Chess &rhs) {
    int lhs_type = orderOfType[tolower(lhs.chess)];
    int rhs_type = orderOfType[tolower(rhs.chess)];
    if (lhs_type == rhs_type) {
        // Policy for black chess
        if (islower(lhs.chess)) {
            if (lhs.y == rhs.y) {
                return (lhs.x < rhs.x);
            }
            return (lhs.y > rhs.y);
        }
            // Policy for white chess
        else {
            if (lhs.y == rhs.y) {
                return (lhs.x < rhs.x);
            }
            return (lhs.y < rhs.y);
        }
    }
    return (lhs_type > rhs_type);
}

vector<Chess> White;
vector<Chess> Black;
vector<vector<char> > chessboard;

inline static
void parse(const string &s) {
    vector<char> tempVec;
    for (size_t i = 2; i < s.size(); i += 4) {
        if (isalpha(s.at(i))) {
            tempVec.emplace_back(s.at(i));
        } else {
            tempVec.emplace_back('\0');
        }
    }
    chessboard.emplace_back(tempVec);
}

inline static
pair<char, int> convert(int row, int col) {
    pair<char, int> result;
    result.first = (char) col + 'a';
    result.second = 8 - row;
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    for (int i = 0; i < 17; ++i) {
        getline(cin, s);
        if (i % 2 != 0) {
            parse(s);
        }
    }

    int row = static_cast<int>(chessboard.size());
    int col = static_cast<int>(chessboard.at(0).size());
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (isupper(chessboard.at(i).at(j))) {
                auto p = convert(i, j);
                White.emplace_back(Chess(chessboard.at(i).at(j), p.first, p.second));
            } else if (islower(chessboard.at(i).at(j))) {
                auto p = convert(i, j);
                Black.emplace_back(Chess(chessboard.at(i).at(j), p.first, p.second));
            }
        }
    }

    sort(White.begin(), White.end(), cmpFunc);
    sort(Black.begin(), Black.end(), cmpFunc);

    // output
    bool firstItem = true;
    cout << "White: ";
    for (const auto &i : White) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ",";
        }
        cout << i.toString();
    }
    cout << endl;

    firstItem = true;
    cout << "Black: ";
    for (const auto &i : Black) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ",";
        }
        cout << i.toString();
    }
    cout << endl;
    return 0;
}
