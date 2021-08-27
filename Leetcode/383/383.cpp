class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool res(true);
        unordered_map<char, int> ransomNoteCnt, magazineCnt;
        for (const auto &i : ransomNote) {
            ++ransomNoteCnt[i];
        }
        for (const auto &i : magazine) {
            ++magazineCnt[i];
        }
        for (const auto it : ransomNoteCnt) {
            if (magazineCnt.find(it.first) == magazineCnt.end() ||
                magazineCnt[it.first] < it.second) {
                res = false;
                break;
            }
        }
        return res;
    }
};