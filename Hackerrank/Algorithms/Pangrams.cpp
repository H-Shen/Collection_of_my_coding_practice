#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    const static int MAXN = 26;
    transform(begin(s), end(s), begin(s), ::tolower);
    unordered_set<char> A(s.begin(), s.end());
    if (A.size() < MAXN || (A.size() == MAXN && A.find(' ') != A.end())) {
        return "not pangram";
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
