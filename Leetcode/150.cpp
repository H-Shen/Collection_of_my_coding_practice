class Solution {
public:
    int evalRPN(vector<string> &tokens) {

        unordered_map<string, int> op = {{"/", 0},
                                         {"+", 0},
                                         {"*", 0},
                                         {"-", 0}};
        auto eval = [](const string &num1, const string &sign, const string &num2) -> int {
            int result;
            int Num1 = stoi(num1);
            int Num2 = stoi(num2);
            if (sign == "+") {
                result = Num2 + Num1;
            } else if (sign == "-") {
                result = Num2 - Num1;
            } else if (sign == "*") {
                result = Num2 * Num1;
            } else if (Num1 == 0) {
                result = 0;
            } else {
                result = Num2 / Num1;
            }
            return result;
        };

        string num1, num2, result;
        stack<string> opList;
        for (size_t i = 0; i != tokens.size(); ++i) {
            if (op.find(tokens[i]) != op.end()) {
                num1 = opList.top();
                opList.pop();
                num2 = opList.top();
                opList.pop();
                result = to_string(eval(num1, tokens[i], num2));
                opList.push(result);
            } else {
                opList.push(tokens[i]);
            }
        }
        return stoi(opList.top());
    }
};