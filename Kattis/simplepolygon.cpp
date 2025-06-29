#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    int x, y, idx;
    double ang;
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    std::cin >> tc;
    while(tc--){
        int n;
        std::cin >> n;
        std::vector<Point> pts(n);
        double sx = 0.0, sy = 0.0;

        // 1) read points; accumulate for centroid
        for(int i = 0; i < n; i++){
            std::cin >> pts[i].x >> pts[i].y;
            pts[i].idx = i;
            sx += pts[i].x;
            sy += pts[i].y;
        }
        double cx = sx / n, cy = sy / n;

        // 2) compute polar angle about (cx,cy)
        for(int i = 0; i < n; i++){
            pts[i].ang = std::atan2(pts[i].y - cy, pts[i].x - cx);
        }

        // 3) sort CCW by angle
        std::sort(pts.begin(), pts.end(),
                  [](const Point &a, const Point &b){
                      return a.ang < b.ang;
                  });

        // 4) find “bottom-most” in this sorted list (min y, then min x)
        int start = 0;
        for(int i = 1; i < n; i++){
            if (pts[i].y < pts[start].y ||
               (pts[i].y == pts[start].y && pts[i].x < pts[start].x))
            {
                start = i;
            }
        }

        // 5) output, rotated so that `start` is first
        for(int k = 0; k < n; k++){
            if(k) std::cout << ' ';
            int idx = (start + k) % n;
            std::cout << pts[idx].idx;
        }
        std::cout << "\n";
    }
    return 0;
}
