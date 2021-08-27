class Solution {
public:
    string repeat(const string &s, int n) {
        string result;
        for (int i = 0; i < n; ++i) result += s;
        return result;
    }
    string originalDigits(string s) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const char &ch : s) ++stats[ch - 'a'];
        string words[MAXN]{};
        words[0] = "zero";
        words[1] = "one";
        words[2] = "two";
        words[3] = "three";
        words[4] = "four";
        words[5] = "five";
        words[6] = "six";
        words[7] = "seven";
        words[8] = "eight";
        words[9] = "nine";
        int answer[MAXN]{};
        // 0z
        while (stats['z'-'a'] > 0) { ++answer[0]; for (const char &ch : words[0]) --stats[ch-'a']; }
        // 2w
        while (stats['w'-'a'] > 0) { ++answer[2]; for (const char &ch : words[2]) --stats[ch-'a']; }
        // 6x
        while (stats['x'-'a'] > 0) { ++answer[6]; for (const char &ch : words[6]) --stats[ch-'a']; }
        // 7s
        while (stats['s'-'a'] > 0) { ++answer[7]; for (const char &ch : words[7]) --stats[ch-'a']; }
        // 5v
        while (stats['v'-'a'] > 0) { ++answer[5]; for (const char &ch : words[5]) --stats[ch-'a']; }
        // 4f
        while (stats['f'-'a'] > 0) { ++answer[4]; for (const char &ch : words[4]) --stats[ch-'a']; }
        // 3r
        while (stats['r'-'a'] > 0) { ++answer[3]; for (const char &ch : words[3]) --stats[ch-'a']; }
        // 8g
        while (stats['g'-'a'] > 0) { ++answer[8]; for (const char &ch : words[8]) --stats[ch-'a']; }
        // 1o
        while (stats['o'-'a'] > 0) { ++answer[1]; for (const char &ch : words[1]) --stats[ch-'a']; }
        // 9i
        while (stats['i'-'a'] > 0) { ++answer[9]; for (const char &ch : words[9]) --stats[ch-'a']; }
        string ret;
        for (int i = 0; i < MAXN; ++i) {
            ret += repeat(to_string(i), answer[i]);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};