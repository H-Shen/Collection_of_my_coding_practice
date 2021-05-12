class Solution {
public:
    vector<string> generatePalindromes(string s) {
        constexpr int MAXN = 26;
        vector<string> result;
        int n = (int)s.size();
        int stats[MAXN]{};
        for (int i = 0; i < n; ++i) {
            ++stats[s[i] - 'a'];
        }
        int counter = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] % 2 != 0) {
                ++counter;
                if (counter > 1) {
                    return result;
                }
            }
        }
        string str, mid;
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] > 0) {
                if (stats[i] % 2 != 0) {
                    mid = string(stats[i], i+'a');
                }
                else {
                    str += string(stats[i] / 2, i+'a');
                }
            }
        }
        int length, midLength;
        string current;
        int index;
        if (mid.empty()) {
            sort(str.begin(), str.end());
            current = s;
            length = (int)str.size();
            do {
                index = 0;
                for (int i = 0; i < length; ++i) {
                    current[index] = str[i];
                    ++index;
                }
                for (int i = length - 1; i >= 0; --i) {
                    current[index] = str[i];
                    ++index;
                }
                result.emplace_back(current);
            } while (next_permutation(str.begin(), str.end()));
        }
        else {
            while (!mid.empty()) {
                midLength = (int)mid.size();
                sort(str.begin(), str.end());
                length = (int)str.size();
                current = s;
                do {
                    index = 0;
                    for (int i = 0; i < length; ++i) {
                        current[index] = str[i];
                        ++index;
                    }
                    for (int i = 0; i < midLength; ++i) {
                        current[index] = mid[i];
                        ++index;
                    }
                    for (int i = length - 1; i >= 0; --i) {
                        current[index] = str[i];
                        ++index;
                    }
                    result.emplace_back(current);
                } while (next_permutation(str.begin(), str.end()));
                
                
                mid.pop_back();
                if (mid.empty()) {
                    break;
                }
                mid.pop_back();
                str.push_back(mid.front());
            }
            sort(result.begin(), result.end());
            result.erase(unique(result.begin(), result.end()), result.end());
        }
        
        return result;
    }
};