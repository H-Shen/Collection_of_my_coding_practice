class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        constexpr int MAXN = 26;
        int rank[MAXN];
        for (size_t i = 0; i != order.size(); ++i) {
            rank[order[i] - 'a'] = i;
        }
        auto f = [&](string &l, const string &r) {
            auto first1 = l.cbegin();
            auto last1 = l.cend();
            auto first2 = r.cbegin();
            auto last2 = r.cend();
            for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
                if (rank[*first1 - 'a'] < rank[*first2 - 'a']) return true;
                if (rank[*first2 - 'a'] < rank[*first1 - 'a']) return false;
            }
            return (first1 == last1) && (first2 != last2);
        };
        return is_sorted(words.begin(), words.end(), f);
    }
};