#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumPerimeterTriangle function below.
vector<int> maximumPerimeterTriangle(vector<int> sticks) {

    using ll = long long;
    struct Triangle {
        ll a, b, c, perimeter;
        Triangle(ll x, ll y, ll z) : a(x), b(y), c(z), perimeter(x + y + z){}
    };

    int n = static_cast<int>(sticks.size());
    sort(sticks.begin(), sticks.end());
    vector <Triangle> triangleList;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (sticks.at(i) + sticks.at(j) > sticks.at(k)) {
                    triangleList.emplace_back(Triangle(sticks.at(i), sticks.at(j), sticks.at(k)));
                }
            }
        }
    }

    vector<int> result;
    if (triangleList.empty()) {
        result.emplace_back(-1);
        return result;
    }

    ll maxPerimeter = (*max_element(triangleList.begin(), triangleList.end(), []
            (const Triangle &A, const Triangle &B) {
        return (A.perimeter < B.perimeter);
    })).perimeter;
    vector <Triangle> temp;
    for (const auto &p : triangleList) {
        if (p.perimeter == maxPerimeter) {
            temp.emplace_back(p);
        }
    }
    ll minShortestLen = (*min_element(temp.begin(), temp.end(), []
            (const Triangle &A, const Triangle &B) {
        return (A.a < B.a);
    })).a;
    for (const auto &p : temp) {
        if (p.a == minShortestLen) {
            result.emplace_back(static_cast<int>(p.a));
            result.emplace_back(static_cast<int>(p.b));
            result.emplace_back(static_cast<int>(p.c));
            break;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split_string(sticks_temp_temp);

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
