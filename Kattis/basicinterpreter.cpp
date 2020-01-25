// https://open.kattis.com/problems/basicinterpreter
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
constexpr size_t MAX_ELEMENTS_IN_AN_ASSIGNMENT = 6;

vector<pair<int, string> > A;
unordered_map<string, int> variableTable;
unordered_map<int, size_t> lineNumberMapping;

inline static
vector<string> split(const string &s) {
    string temp;
    vector<string> result;
    istringstream iss(s);
    while (getline(iss, temp, ' ')) {
        result.emplace_back(temp);
    }
    return result;
}

// "123" --> 123
// "varName" --> (ll)A[varName]
inline static
ll toNumber(const string &s) {
    bool isANumber = true;
    for (const char &ch : s) {
        if (!isdigit(ch) && ch != '-') {
            isANumber = false;
            break;
        }
    }
    if (isANumber) {
        return stol(s);
    }
    return static_cast<ll>(variableTable[s]);
}

inline static
void assign(const vector<string> &s) {
    auto it = s.cbegin();
    ++it;
    string lhs = *it;
    advance(it, 2);
    // Case 1: LET varName = operand1 operator_ operand2
    if (s.size() == MAX_ELEMENTS_IN_AN_ASSIGNMENT) {
        string operand1 = *it;
        ++it;
        string operator_ = *it;
        ++it;
        string operand2 = *it;
        if (operator_ == "+") {
            variableTable[lhs] = static_cast<int>(toNumber(operand1) + toNumber(operand2));
        } else if (operator_ == "-") {
            variableTable[lhs] = static_cast<int>(toNumber(operand1) - toNumber(operand2));
        } else if (operator_ == "*") {
            variableTable[lhs] = static_cast<int>(toNumber(operand1) * toNumber(operand2));
        } else if (operator_ == "/") {
            variableTable[lhs] = static_cast<int>(toNumber(operand1) / toNumber(operand2));
        }
    }
        // Case 2: LET varName = operand
    else {
        string operand1 = *it;
        variableTable[lhs] = static_cast<int>(toNumber(operand1));
    }
}

inline static
bool compare(const string &lhs, const string &operator_, const string &rhs) {
    ll lhsNumber = toNumber(lhs);
    ll rhsNumber = toNumber(rhs);
    if (operator_ == "=") {
        return lhsNumber == rhsNumber;
    } else if (operator_ == ">") {
        return lhsNumber > rhsNumber;
    } else if (operator_ == ">=") {
        return lhsNumber >= rhsNumber;
    } else if (operator_ == "<") {
        return lhsNumber < rhsNumber;
    } else if (operator_ == "<=") {
        return lhsNumber <= rhsNumber;
    }
    return lhsNumber != rhsNumber;
}

inline static
void print(const string &s, const bool &newLine) {

    bool isLiteralString = false;
    for (const char &i : s) {
        if (i == '"') {
            isLiteralString = true;
            break;
        }
    }

    // print literal string
    if (isLiteralString) {
        bool insideQuotes = false;
        for (const char &i : s) {
            if (insideQuotes) {
                if (i != '"') {
                    cout << i;
                }
            } else if (i == '"') {
                insideQuotes = true;
            }
        }
    }
    // print a variable
    else {
        string variableName;
        size_t i = 0;
        for (; s[i] != ' '; ++i);
        i++;
        for (; i != s.size(); ++i) {
            variableName.push_back(s[i]);
        }
        cout << variableTable[variableName];
    }

    if (newLine) {
        cout << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    vector<string> p;
    int val;
    while (cin >> val) {
        getline(cin, s);
        A.emplace_back(make_pair(val, s.substr(1)));
    }
    sort(A.begin(), A.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return (a.first < b.first);
    });

    for (size_t i = 0; i != A.size(); ++i) {
        lineNumberMapping[A[i].first] = i;
    }

    for (size_t i = 0; i != A.size();) {
        p = split(A[i].second);
        // PRINT
        if (p.front() == "PRINT") {
            print(A[i].second, false);
            ++i;
        }
        // PRINTLN
        else if (p.front() == "PRINTLN") {
            print(A[i].second, true);
            ++i;
        }
        // LET
        else if (p.front() == "LET") {
            assign(p);
            ++i;
        }
        // IF THEN GOTO
        else {
            auto iter = p.cbegin();
            ++iter;
            string lhs = *iter;
            ++iter;
            string operator_ = *iter;
            ++iter;
            string rhs = *iter;
            if (compare(lhs, operator_, rhs)) {
                advance(iter, 3);
                i = lineNumberMapping[stoi(*iter)];
            } else {
                ++i;
            }
        }
    }
    return 0;
}
