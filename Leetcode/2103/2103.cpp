class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,set<char>> unmap;
        int n = (int)rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pos = rings[i+1];
            unmap[pos].insert(color);
        }
        int counter = 0;
        for (auto&[k,v] : unmap) {
            if (v.size() == 3) ++counter;
        }
        return counter;
    }
};