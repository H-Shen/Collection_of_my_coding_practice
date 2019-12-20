// https://ac.nowcoder.com/acm/problem/15661

#include <bits/stdc++.h>

using namespace std;
const string A[] = {"012345", "6789AB", "CDEFGH",
                    "IJKLMN", "OPQRST", "UVWXYZ"};
const size_t LEN = 6;

int main()
{
    ios_base::sync_with_stdio(false);
    unordered_map <char, int> key2Row, key2Col;
    for (size_t i = 0; i < LEN; ++i)
    {
        for (size_t j = 0; j < LEN; ++j)
        {
            key2Row[A[i][j]] = static_cast<int>(i);
            key2Col[A[i][j]] = static_cast<int>(j);
        }
    }
    int rowFreqList[LEN] = {0};
    int colFreqList[LEN] = {0};

    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        memset(rowFreqList, 0, sizeof(rowFreqList));
        memset(colFreqList, 0, sizeof(colFreqList));

        for (char i : s)
        {
            ++rowFreqList[key2Row[i]];
            ++colFreqList[key2Col[i]];
        }
        int maxFreqRow = *max_element(begin(rowFreqList), end(rowFreqList));
        int maxFreqCol = *max_element(begin(colFreqList), end(colFreqList));

        string res;
        for (auto it = key2Row.cbegin(); it != key2Row.cend(); ++it)
        {
            if (rowFreqList[key2Row[it->first]] == maxFreqRow &&
                colFreqList[key2Col[it->first]] == maxFreqCol)
            {
                res += it->first;
            }
        }

        sort(res.begin(), res.end(), [&](const char &a, const char &b)
        {
            if (key2Row[a] == key2Row[b])
            {
                return (key2Col[a] < key2Col[b]);
            }
            return (key2Row[a] < key2Row[b]);
        });
        cout << res << endl;
    }

    return 0;
}