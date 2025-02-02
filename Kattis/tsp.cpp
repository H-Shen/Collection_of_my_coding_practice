// https://open.kattis.com/problems/tsp
//

#include <bits/extc++.h>

using namespace std;

struct Point {
    double x, y;
};

inline
int calcDistance(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double d = sqrt(dx * dx + dy * dy);
    return static_cast<int>(round(d));
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int d = calcDistance(points[i], points[j]);
            dist[i][j] = d;
            dist[j][i] = d;
        }
    }
    
    vector<bool> visited(n, false);
    vector<int> tour;
    tour.reserve(n);
    int current = 0;
    tour.push_back(current);
    visited[current] = true;

    for (int i = 1; i < n; i++){
        int next = -1;
        int best_d = numeric_limits<int>::max();
        for (int j = 0; j < n; j++){
            if (!visited[j] && dist[current][j] < best_d){
                best_d = dist[current][j];
                next = j;
            }
        }
        if (next == -1) break;
        tour.push_back(next);
        visited[next] = true;
        current = next;
    }
    auto tourCost = [&]() -> int {
        int cost = 0;
        for (int i = 0; i < n-1; i++){
            cost += dist[tour[i]][tour[i+1]];
        }
        cost += dist[tour[n-1]][tour[0]]; 
        return cost;
    };
    int currentCost = tourCost();
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 1; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                int a = tour[i - 1];
                int b = tour[i];
                int c = tour[j];
                int d = (j == n - 1) ? tour[0] : tour[j + 1];
                int delta = 0;
                delta -= dist[a][b];
                delta -= dist[c][d];
                delta += dist[a][c];
                delta += dist[b][d];
                if (delta < 0) {
                    reverse(tour.begin() + i, tour.begin() + j + 1);
                    currentCost += delta;
                    improved = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << tour[i] << '\n';
    }
    return 0;
}
