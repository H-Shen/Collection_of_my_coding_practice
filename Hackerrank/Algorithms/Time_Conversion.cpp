#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string result;
    if (s.substr(s.size() - 2) == "AM") {
        if (s.substr(0, 2) == "12") {
            // Case 1
            result = "00" + s.substr(2, s.size() - 4);
        } else {
            // Case 2
            result = s.substr(0, s.size() - 2);
        }
    } else {
        if (s.substr(0, 2) == "12") {
            // Case 3
            result = "12" + s.substr(2, s.size() - 4);
        } else {
            // Case 4
            result = to_string(stoi(s.substr(0, 2)) + 12) + s.substr(2, s.size() - 4);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
