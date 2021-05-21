class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int types = unique(candyType.begin(),candyType.end()) - candyType.begin();
        int n = (int)candyType.size();
        return min(n >> 1, types);
    }
};