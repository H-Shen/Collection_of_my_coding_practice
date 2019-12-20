// https://www.nowcoder.com/practice/8380c8cf28954a188362206b1991b5d6

class Permutation {
public:
    vector <string> getPermutation(string A) {
        // write code here
        vector <pair<char, size_t>> A_copy(A.size());
        for (size_t i = 0; i != A_copy.size(); ++i) {
            A_copy.at(i) = make_pair(A.at(i), i);
        }

        auto cmp = [](const pair<char, size_t> &lhs, const pair<char, size_t> &rhs) {
            if (lhs.first == rhs.first) {
                return (lhs.second > rhs.second);
            }
            return (lhs.first > rhs.first);
        };

        vector <string> result;
        sort(A_copy.begin(), A_copy.end(), cmp);
        string s;
        do {
            for (const auto &it : A_copy) {
                s += it.first;
            }
            result.emplace_back(s);
            string().swap(s);
        } while (next_permutation(A_copy.begin(), A_copy.end(), cmp));
        sort(result.begin(), result.end(), [](const string &lhs, const string &rhs) {
            return (lhs > rhs);
        });
        return result;
    }
};