// write your code here cpp

// https://www.nowcoder.com/practice/82215ba86ace4a2690fd9ded27fe9f49

#include <bits/stdc++.h>

using namespace std;

const unordered_map<string, int> op = {{"/", 0},
                                       {"+", 0},
                                       {"*", 0},
                                       {"-", 0}};

int convert(const string &n) {
    stringstream ss;
    int result;
    ss << n;
    ss >> result;
    return result;
}

int eval(const string &num1, const string &sign, const string &num2) {
    int result;
    int Num1 = convert(num1), Num2 = convert(num2);
    if (sign == "+")
        result = Num2 + Num1;
    else if (sign == "-")
        result = Num2 - Num1;
    else if (sign == "*")
        result = Num2 * Num1;
    else {
        if (Num1 == 0)
            return 0;
        else
            result = Num2 / Num1;
    }
    return result;
}


int evalPN(vector<string> &tokens) {
    string num1, num2, result;
    stack<string> opList;
    int len = tokens.size();
    for (int i = 0; i < len; i++) {
        if (op.find(tokens[i]) != op.end()) {
            num1 = opList.top();
            opList.pop();
            num2 = opList.top();
            opList.pop();
            result = to_string(eval(num2, tokens[i], num1));
            opList.push(result);
        } else {
            opList.push(tokens[i]);
        }
    }
    return convert(opList.top());
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        cout << evalPN(a) << endl;
    }
    return 0;
}