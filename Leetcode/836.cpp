class Solution {
public:
    bool intervalOverlap(int a1, int a2, int a3, int a4) {
        return (a1 < a3 && a3 < a2) || (a1 < a4 && a4 < a2) || (a3 < a1 && a1 < a4) || (a3 < a2 && a2 < a4);
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];
        
        // If the rectangle has 0 of width or 0 of height
        if (x1 == x2 || y1 == y2 || x3 == x4 || y3 == y4) {
            return false;
        }
        // Check if their intervals on x-axis are overlapped and their intervals on y- axis are overlapped
        return intervalOverlap(x1, x2, x3, x4) && intervalOverlap(y1, y2, y3, y4);
    }
};