class Solution {
public:
    int countVowelStrings(int n) {
        // C(4+n,n) 
        // = C(4+n, 4)
        // = (4+n)! / (4! * n!)
        // = (n+1)(n+2)(n+3)(n+4) / 24
        return (n+1)*(n+2)*(n+3)*(n+4) / 24;
    }
};