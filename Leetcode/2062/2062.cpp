constexpr int MAXN = 26;

class Solution {
public:
    bool check(string&word, int l, int r) {
        int stats[MAXN]{};        
        for (int i = l; i <= r; ++i) {
            if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') return false;
            ++stats[word[i]-'a'];
        }
        return stats['a'-'a'] > 0 && stats['e'-'a'] > 0 && stats['i'-'a'] > 0 && stats['o'-'a'] > 0 && stats['u'-'a'] > 0;
    }
    int countVowelSubstrings(string word) {
        int n = (int)word.size();
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (check(word, i, j)) ++counter;
            }
        }
        return counter;
    }
};