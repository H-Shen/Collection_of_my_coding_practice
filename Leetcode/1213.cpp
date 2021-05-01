class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> temp;
        set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(temp));
        vector<int> temp2;
        set_intersection(temp.begin(), temp.end(), arr3.begin(), arr3.end(), back_inserter(temp2));
        return temp2;
    }
};