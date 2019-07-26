class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        string A[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                      "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        unordered_set<string> res;
        string tmp;
        for (const auto &i : words) {
            for (const auto &ch : i) {
                tmp += A[ch - 'a'];
            }
            res.insert(tmp);
            tmp = "";
        }

        return res.size();
    }
};