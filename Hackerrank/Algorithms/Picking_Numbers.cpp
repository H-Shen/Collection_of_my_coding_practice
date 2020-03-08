#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    unordered_map<int, int> unmap;
    for (const auto &i : a) {
        ++unmap[i];
    }
    vector<pair<int, int> > vec(unmap.begin(), unmap.end());
    sort(vec.begin(), vec.end(), [](const pair<int, int> &l, const pair<int, int> &r)    {
        return (l.first < r.first);
    });
    int max_val = 0;
    // Case 1:
    for (size_t i = 0; i != vec.size(); ++i) {
        max_val = max(max_val, vec.at(i).second);
    }
    // Case 2:
    for (size_t i = 1; i != vec.size(); ++i) {
        if (abs(vec.at(i).first - vec.at(i - 1).first) <= 1) {
            max_val = max(max_val, vec.at(i).second + vec.at(i - 1).second);
        }
    }
    return max_val;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
