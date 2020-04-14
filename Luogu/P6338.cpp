#include<bits/extc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int r, c;
    cin >> r >> c;
    string s;
    vector <vector<char> > A(r, vector<char>(c));

    for (auto &&i : A)
    {
        cin >> s;
        for (int j = 0; j < c; ++j)
        {
            i[j] = s[j];
        }
    }

    vector <string> ans;
    string str;
    for (const auto &i : A)
    {
        for (const auto &j : i)
        {
            if (j == '#' && str != "")
            {
                if (str.size() >= 2)
                {
                    ans.push_back(str);
                }
                str = "";
            }
            else if (j != '#')
            {
                str = str + j;
            }
        }
        if (str != "")
        {
            if (str.size() >= 2)
            {
                ans.push_back(str);
            }
            str = "";
        }
    }

    str = "";
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            if (A[j][i] == '#' && str != "")
            {
                if (str.size() >= 2)
                {
                    ans.push_back(str);
                }
                str = "";
            }
            else if (A[j][i] != '#')
            {
                str = str + A[j][i];
            }
        }
        if (str != "")
        {
            if (str.size() >= 2)
            {
                ans.push_back(str);
            }
            str = "";
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << '\n';

    return 0;
}
