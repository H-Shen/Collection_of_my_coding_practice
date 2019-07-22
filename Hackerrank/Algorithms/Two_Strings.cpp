#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    auto getIntersection = [](const string &A, const string &B) -> unordered_set<char> {
        vector<char> vec_A(A.begin(), A.end());
        vector<char> vec_B(B.begin(), B.end());
        sort(vec_A.begin(), vec_A.end());
        sort(vec_B.begin(), vec_B.end());
        vector<char> vec_result;
        set_intersection(vec_A.begin(), vec_A.end(), vec_B.begin(), vec_B.end(), back_inserter(vec_result));
        return unordered_set<char>(vec_result.begin(), vec_result.end());
    };

    if (getIntersection(s1, s2).empty()) {
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
