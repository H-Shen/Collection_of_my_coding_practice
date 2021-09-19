constexpr int MAXN = 1005;

class DetectSquares {
public:
    int freq[MAXN][MAXN];
    int minX = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int minY = numeric_limits<int>::max();
    int maxY = numeric_limits<int>::min();
    int size = 0;
    DetectSquares() {
        memset(freq, 0, sizeof freq);
    }
    
    void add(vector<int> point) {
        ++freq[point[0]][point[1]];
        minX = min(minX, point[0]);
        maxX = max(maxX, point[0]);
        minY = min(minY, point[1]);
        maxY = max(maxY, point[1]);
        ++size;
    }
    
    int count(vector<int> point) {
        if (size < 3) return 0; 
        int counter = 0;
        int x = point[0];
        int y = point[1];
        //
        for (int r = 1;; ++r) {
            if (x-r < minX || y-r < minY) break;
            counter += freq[x-r][y] * freq[x-r][y-r] * freq[x][y-r];
        }
        //
        for (int r = 1;; ++r) {
            if (x-r < minX || y+r > maxY) break;
            counter += freq[x-r][y] * freq[x-r][y+r] * freq[x][y+r];
        }
        //
        for (int r = 1;; ++r) {
            if (x+r > maxX || y+r > maxY) break;
            counter += freq[x][y+r] * freq[x+r][y+r] * freq[x+r][y];
        }
        //
        for (int r = 1;; ++r) {
            if (x+r > maxX || y-r < minY) break;
            counter += freq[x+r][y] * freq[x+r][y-r] * freq[x][y-r];
        }
        return counter;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */