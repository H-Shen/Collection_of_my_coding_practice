// https://open.kattis.com/problems/maxcolinear
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <chrono>

using namespace std;
using ll = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

int solve(int n) {
    // Read in the points.
    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }

    // If there is less than 2 points, the answer is simply n.
    if(n < 2){
        return n;
    }
    int ans = 1;

    // Iterate through each point as the "anchor".
    for (int i = 0; i < n; i++){
        // Use an unordered_map to count points with the same slope.
        // We encode the slope (dy, dx) into a single key.
        unordered_map<pair<int,int>,int, custom_hash> slopeCount;

        int duplicate = 0; // Count duplicate points.
        int vertical = 0;  // Count points that form a vertical line with the anchor.
        int dx, dy;
        // Compare the anchor with every point coming after it.
        for (int j = i + 1; j < n; j++){
            dx = points[j].first - points[i].first;
            dy = points[j].second - points[i].second;
            // Check for duplicate points.
            if(dx == 0 && dy == 0){
                duplicate++;
            }
                // Check for a vertical line.
            else if(dx == 0){
                vertical++;
            }
            else {
                // Reduce the fraction (dy/dx) to its simplest form.
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                // Normalize the representation so that dx is always positive.
                if(dx < 0){
                    dx = -dx;
                    dy = -dy;
                }
                slopeCount[{dx, dy}]++;
            }
        }
        // The maximum collinear count for this anchor.
        int currentMax = vertical;
        for(auto &entry : slopeCount){
            currentMax = max(currentMax, entry.second);
        }
        // Add one for the anchor point itself and any duplicate points.
        ans = max(ans, currentMax + duplicate + 1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cout << solve(n) << '\n';
    }
    return 0;
}
