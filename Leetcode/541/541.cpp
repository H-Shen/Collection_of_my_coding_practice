class Solution {
public:
    string reverseStr(string s, int k) {
        int n = (int)s.size();
        int temp = n % (2*k);
        int count = n / (2*k);
        // Case 1:
        if (temp == 0) {
            for (int i = 0; i < count; ++i) {
                reverse(s.begin()+i*2*k, s.begin()+i*2*k+k);
            }
        }
        // Case 2:
        else if (temp < k) {
            for (int i = 0; i < count; ++i) {
                reverse(s.begin()+i*2*k, s.begin()+i*2*k+k);
            }
            reverse(s.begin()+(int)s.size()-temp, s.end());
        }
        // Case 3:
        else {
            for (int i = 0; i < count; ++i) {
                reverse(s.begin()+i*2*k, s.begin()+i*2*k+k);
            }
            reverse(s.begin()+(int)s.size()-temp, s.begin()+(int)s.size()-temp+k);                                                                                                                                           
        }
        return s;
    }
};