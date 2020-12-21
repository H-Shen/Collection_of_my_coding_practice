#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

enum class DIR : int {
    NORTH, SOUTH, EAST, WEST
};

pii getStep(DIR dir) {
    switch (dir) {
        case DIR::NORTH:
            return {-1, 0};
        case DIR::SOUTH:
            return {1, 0};
        case DIR::EAST:
            return {0, 1};
        case DIR::WEST:
            return {0, -1};
    }
    return {0, 0};
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

unordered_set<pii, custom_hash> points;
struct Node {
    int x, y, time;
    DIR direction;
    Node(int x, int y, int time, DIR direction) : x(x), y(y), time(time), direction(direction) {}
    explicit Node() = default;
};
void bfs(int n) {
    queue<Node> q;
    q.push({0, 0, n, DIR::NORTH});
    q.push({0, 0, n, DIR::SOUTH});
    q.push({0, 0, n, DIR::WEST});
    q.push({0, 0, n, DIR::EAST});
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        if (cur.time == 0) {
            points.insert({cur.x, cur.y});
            continue;
        }
        int new_x, new_y, new_time;
        DIR new_direction;
        pii change;
        switch (cur.direction) {
            case DIR::SOUTH:
            case DIR::NORTH:
                new_direction = DIR::WEST;
                change = getStep(new_direction);
                new_x = cur.x + change.first;
                new_y = cur.y + change.second;
                new_time = cur.time - 1;
                q.push({new_x, new_y, new_time, new_direction});

                new_direction = DIR::EAST;
                change = getStep(new_direction);
                new_x = cur.x + change.first;
                new_y = cur.y + change.second;
                new_time = cur.time - 1;
                q.push({new_x, new_y, new_time, new_direction});
                break;
            case DIR::WEST:
            case DIR::EAST:
                new_direction = DIR::SOUTH;
                change = getStep(new_direction);
                new_x = cur.x + change.first;
                new_y = cur.y + change.second;
                new_time = cur.time - 1;
                q.push({new_x, new_y, new_time, new_direction});

                new_direction = DIR::NORTH;
                change = getStep(new_direction);
                new_x = cur.x + change.first;
                new_y = cur.y + change.second;
                new_time = cur.time - 1;
                q.push({new_x, new_y, new_time, new_direction});
                break;
        }
    }
}

ll solve(int n) {
    points.clear();
    bfs(n);
    return points.size();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // {4,4,12,9,24,16,40,25,60,36,84,49,112,64,144,81,180,100,220,121,264,144,312,169,364,}
    // find patterns by the array above, which is obtained by bfs
    int n;
    cin >> n;
    if (n & 1) {
        ll temp = n >> 1;
        cout << 2 * (temp + 1) * (temp + 2) << '\n';
    } else {
        ll temp = (n >> 1) + 1;
        cout << temp * temp << '\n';
    }


    return 0;
}