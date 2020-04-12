#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 300;
constexpr int MINN = -300;
constexpr int MAX_LEN_STR = 150;
char operations[MAX_LEN_STR];

struct Pos {
    int x, y, z;

    Pos &operator=(Pos other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Pos() = default;

    bool operator==(const Pos &other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    friend ostream &operator<<(ostream &os, const Pos &pos) {
        os << "x: " << pos.x << " y: " << pos.y << " z: " << pos.z;
        return os;
    }
};

// (f,h) to (x,y,z)
Pos convert[10][10];

struct Drone {
    bool isAlive = true;
    int id, atk, def, mat, mdf, fix, hp;
    Pos pos;
    int f, h;

    void up() {
        if (h == 4) {
            return;
        }
        ++h;
    }

    void down() {
        if (h == 0) {
            return;
        }
        --h;
    }

    void left() {
        ++f;
        if (f > 7) {
            f = 0;
        }
    }

    void right() {
        --f;
        if (f < 0) {
            f = 7;
        }
    }

    void restore() {
        hp += fix;
    }

    bool operator==(const Drone &other) const {
        return id == other.id;
    }

    friend ostream &operator<<(ostream &os, const Drone &drone) {
        os << "isAlive: " << drone.isAlive << " id: " << drone.id << " atk: "
           << drone.atk << " def: " << drone.def << " mat: " << drone.mat
           << " mdf: " << drone.mdf << " fix: " << drone.fix << " hp: "
           << drone.hp << " pos: " << drone.pos << " f: " << drone.f << " h: "
           << drone.h;
        return os;
    }
};

struct my_hash_func {
    size_t operator()(const Pos &pos) const {
        return hash<int>()(pos.x) * MAXN * MAXN + hash<int>()(pos.y) * MAXN +
               hash<int>()(pos.z);
    }
};

unordered_map<Pos, unordered_set<int>, my_hash_func> pos2dronesId;
unordered_map<int, Drone> id2drone;

inline static
void forward(int id) {
    Drone &drone = id2drone[id];
    // Update pos2dronesId
    pos2dronesId[drone.pos].erase(id);
    auto p = convert[drone.f][drone.h];
    drone.pos.x += p.x;
    drone.pos.y += p.y;
    drone.pos.z += p.z;
    pos2dronesId[drone.pos].insert(id);
}

inline static
void missile_attack(int id) {
    Drone drone = id2drone[id];
    auto direction = convert[drone.f][drone.h];
    Pos temp = drone.pos;
    while (temp.x >= MINN && temp.x <= MAXN && temp.y >= MINN &&
           temp.y <= MAXN && temp.z <= MAXN && temp.z >= MINN) {
        // Linear check the current direction
        temp.x += direction.x;
        temp.y += direction.y;
        temp.z += direction.z;
        // Check if there are alive drones in the current position
        if (!pos2dronesId[temp].empty()) {
            unordered_set<int> unset = pos2dronesId[temp];
            int minimal_id = numeric_limits<int>::max();
            for (const auto &i : unset) {
                minimal_id = min(minimal_id, i);
            }
            int cost = drone.atk - id2drone[minimal_id].def;
            if (cost > 0) {
                id2drone[minimal_id].hp -= cost;
            }
            // If the drone has no hp, remove it from pos2dronesId
            if (id2drone[minimal_id].hp <= 0) {
                id2drone[minimal_id].isAlive = false;
                pos2dronesId[temp].erase(minimal_id);
            }
            break;
        }
    }
}

inline static
void beam_attack(int id) {
    Drone drone = id2drone[id];
    auto direction = convert[drone.f][drone.h];
    Pos temp = drone.pos;
    while (temp.x >= MINN && temp.x <= MAXN && temp.y >= MINN &&
           temp.y <= MAXN && temp.z <= MAXN && temp.z >= MINN) {
        temp.x += direction.x;
        temp.y += direction.y;
        temp.z += direction.z;
        if (!pos2dronesId[temp].empty()) {
            vector<int> destroyedDroneIdVec;
            for (const auto &currentId : pos2dronesId[temp]) {
                int cost = drone.mat - id2drone[currentId].mdf;
                if (cost > 0) {
                    id2drone[currentId].hp -= cost;
                }
                if (id2drone[currentId].hp <= 0) {
                    destroyedDroneIdVec.emplace_back(currentId);
                }
            }
            for (const auto &destroyedDroneId : destroyedDroneIdVec) {
                pos2dronesId[temp].erase(destroyedDroneId);
                id2drone[destroyedDroneId].isAlive = false;
            }
        }
    }
}

vector<string> instructionsForEachDrone;

void pre() {
    convert[0][0] = {0, 0, -1};
    convert[0][1] = {1, 0, -1};
    convert[0][2] = {1, 0, 0};
    convert[0][3] = {1, 0, 1};
    convert[0][4] = {0, 0, 1};
    convert[1][0] = {0, 0, -1};
    convert[1][1] = {1, 1, -1};
    convert[1][2] = {1, 1, 0};
    convert[1][3] = {1, 1, 1};
    convert[1][4] = {0, 0, 1};
    convert[2][0] = {0, 0, -1};
    convert[2][1] = {0, 1, -1};
    convert[2][2] = {0, 1, 0};
    convert[2][3] = {0, 1, 1};
    convert[2][4] = {0, 0, 1};
    convert[3][0] = {0, 0, -1};
    convert[3][1] = {-1, 1, -1};
    convert[3][2] = {-1, 1, 0};
    convert[3][3] = {-1, 1, 1};
    convert[3][4] = {0, 0, 1};
    convert[4][0] = {0, 0, -1};
    convert[4][1] = {-1, 0, -1};
    convert[4][2] = {-1, 0, 0};
    convert[4][3] = {-1, 0, 1};
    convert[4][4] = {0, 0, 1};
    convert[5][0] = {0, 0, -1};
    convert[5][1] = {-1, -1, -1};
    convert[5][2] = {-1, -1, 0};
    convert[5][3] = {-1, -1, 1};
    convert[5][4] = {0, 0, 1};
    convert[6][0] = {0, 0, -1};
    convert[6][1] = {0, -1, -1};
    convert[6][2] = {0, -1, 0};
    convert[6][3] = {0, -1, 1};
    convert[6][4] = {0, 0, 1};
    convert[7][0] = {0, 0, -1};
    convert[7][1] = {1, -1, -1};
    convert[7][2] = {1, -1, 0};
    convert[7][3] = {1, -1, 1};
    convert[7][4] = {0, 0, 1};
}

int main() {

    // pre
    pre();
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; ++i) {
        Drone drone{};
        drone.id = i;
        scanf("%d %d %d %d %d %d %d %d %d %d %d %s",
              &drone.pos.x,
              &drone.pos.y,
              &drone.pos.z,
              &drone.h,
              &drone.f,
              &drone.atk,
              &drone.def,
              &drone.mat,
              &drone.mdf,
              &drone.hp,
              &drone.fix,
              operations);
        id2drone[drone.id] = drone;
        pos2dronesId[drone.pos].insert(drone.id);
        instructionsForEachDrone.emplace_back(operations);
    }
    for (int current_time = 0; current_time < t; ++current_time) {
        for (int i = 0; i < n; ++i) {
            if (id2drone[i].isAlive) {
                forward(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (id2drone[i].isAlive) {
                switch (instructionsForEachDrone.at(i).at(current_time)) {
                    case 'N':
                        break;
                    case 'U':
                        id2drone[i].up();
                        break;
                    case 'D':
                        id2drone[i].down();
                        break;
                    case 'L':
                        id2drone[i].left();
                        break;
                    case 'R':
                        id2drone[i].right();
                        break;
                    case 'F':
                        id2drone[i].restore();
                        break;
                    case 'A':
                        missile_attack(i);
                        break;
                    case 'M':
                        beam_attack(i);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d ", id2drone[i].pos.x, id2drone[i].pos.y,
               id2drone[i].pos.z);
        if (id2drone[i].isAlive) {
            printf("%d\n", id2drone[i].hp);
        } else {
            printf("0\n");
        }
    }

    return 0;
}