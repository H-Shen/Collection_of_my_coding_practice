class Solution {
public:
    bool isValid(const vector<int> &A) {
        if (A[0] > 2) {
            return false;
        }
        if (A[0] == 2 && A[1] > 3) {
            return false;
        }
        if (A[2] > 5) {
            return false;
        }
        return true;
    }
    int convert(const vector<int> &A) {
        return (A[0]*10+A[1])*60 + A[2]*10+A[3];
    }
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> vec;
        do {
            if (isValid(arr)) {
                if (vec.empty()) {
                    vec = arr;
                }
                else if (convert(vec) < convert(arr)) {
                    vec = arr;
                } 
            }
        } while (next_permutation(arr.begin(),arr.end()));
        string ans;
        if (vec.empty()) {
            return ans;
        }
        ans.push_back(vec[0] + '0');
        ans.push_back(vec[1] + '0');
        ans.push_back(':');
        ans.push_back(vec[2] + '0');
        ans.push_back(vec[3] + '0');
        return ans;
    }
};