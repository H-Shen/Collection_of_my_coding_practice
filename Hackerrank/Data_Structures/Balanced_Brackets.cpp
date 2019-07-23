#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    int len = s.length();
    char cmp;
    stack<char> A;
    for (int i = 0; i < len; i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            A.push(s[i]);
        else {
            if (A.empty())
                return "NO";
            else {
                cmp = A.top();
                if ((s[i] == ')' && cmp != '(') || (s[i] == '}' && cmp != '{') || (s[i] == ']' && cmp != '['))
                    return "NO";
                A.pop();
            }
        }
        if (i == len - 1 && !A.empty())
            return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
