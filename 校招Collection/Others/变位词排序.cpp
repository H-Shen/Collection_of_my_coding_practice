// https://www.nowcoder.com/practice/764edc8f2a6147429a098f422753853b

#include <bits/stdc++.h>

using namespace std;

class SortString {
public:
    vector<string> sortStrings(vector<string> str, int n) {

        if (n <= 1)
            return str;

        auto minString = [](vector<string> &str) {
            string minVal = str[0];
            for (const string &i : str) {
                if (i < minVal)
                    minVal = i;
            }
            return minVal;
        };

        unordered_map<string, vector<string>> A;
        for (const auto &i : str) {
            string a(i);
            multiset<char> temp;
            for (auto j : a)
                temp.insert(j);
            string b(temp.begin(), temp.end());
            A[b].emplace_back(a);
        }

        vector<string> result;
        for (auto &it : A)
            result.push_back(minString(it.second));
        sort(result.begin(), result.end());
        return result;
    }
};