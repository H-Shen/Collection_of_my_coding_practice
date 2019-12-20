// https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe

class Solution {
public:
    vector <vector<int>> FindContinuousSequence(int s) {
        vector <vector<int>> res;
        int n = 2;
        int a;

        while (n * n < 2 * s) {

            if ((2 * s % n == 0) && (2 * s / n + 1 - n) % 2 == 0) {
                a = (2 * s / n + 1 - n) / 2;
                vector<int> tmp(static_cast<unsigned long>(n));
                iota(tmp.begin(), tmp.end(), a);
                res.push_back(tmp);
            }
            ++n;
        }

        sort(res.begin(), res.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a.front() < b.front());
        });
        return res;
    }
};