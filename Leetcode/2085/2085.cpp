class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> unmap1;
        for (auto&i : words1) {
            ++unmap1[i];
        }
        unordered_map<string,int> unmap2;
        for (auto&i : words2) {
            ++unmap2[i];
        }
        int counter = 0;
        for (auto &[k,v] : unmap1) {
            if (v == 1 && unmap2.find(k) != unmap2.end() && unmap2[k] == 1) ++counter;
        }
        return counter;
    }
};