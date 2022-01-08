class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> unmap;
        int n = (int)words.size();
        for (auto&i : words) {
            ++unmap[i];
        }
        int length = 0;
        // choose the biggest odd number
        string str;
        int maxOdd = 0;
        for (auto&[k,v] : unmap) {
            if (k[0] == k[1] && v & 1 && maxOdd < v) {
                str = k;
                maxOdd = v;
            }
        }
        if (maxOdd > 0) {
            length += (maxOdd << 1);
            unmap.erase(str);
        }
        string temp;
        temp.resize(2);
        while (!unmap.empty()) {
            auto iter = unmap.begin();
            if (iter->first[0] == iter->first[1]) {
                if (iter->second & 1) {
                    length += ((iter->second-1) << 1);
                }
                else {
                    length += (iter->second << 1);
                }
                unmap.erase(iter);
            }
            else {
                temp[0] = iter->first[1];
                temp[1] = iter->first[0];
                if (unmap.count(temp) > 0) {
                    length += (min(iter->second << 1, unmap[temp] << 1) << 1);
                    unmap.erase(iter);
                    unmap.erase(temp);
                }
                else {
                    unmap.erase(iter);
                }
            }
            
        }
        
        return length;
    }
};