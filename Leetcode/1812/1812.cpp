class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int i = 8 - (int)(coordinates[1] - '0');
        int j = coordinates[0] - 'a';
        return (i+j) % 2 == 0;
    }
};