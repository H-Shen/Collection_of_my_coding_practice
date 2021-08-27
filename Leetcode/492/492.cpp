class Solution {
public:
    vector<int> constructRectangle(int area) {
        int n = sqrt(area*1.0)+1;
        int diff = numeric_limits<int>::max();
        int result_l = 0, result_w = 0;
        for (int w = n; w >= 1; --w) {
            if (area % w == 0) {
                int l = area / w;
                if (l >= w) {
                    if (abs(l-w) < diff) {
                        diff = abs(l-w);
                        result_l = l;
                        result_w = w;
                    }
                }
            }
        }
        return vector<int>{result_l, result_w};
    }
};