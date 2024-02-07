class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        auto p = *max_element(dimensions.begin(),dimensions.end(),
                             [](const vector<int>&l, const vector<int>&r){
                                    int a = l[0]*l[0]+l[1]*l[1];
                                    int b = r[0]*r[0]+r[1]*r[1];
                                    if (a == b) {
                                        return l[0]*l[1] < r[0]*r[1];
                                    }
                                    return a < b;
                             });
        return p[0]*p[1];
    }
};