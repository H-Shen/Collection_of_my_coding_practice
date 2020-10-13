#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;

namespace IO {
    inline
    void read_alpha(char &t) {
        int c = getchar_unlocked();
        t = 0;
        while (!isalpha(c)) c = getchar_unlocked();
        while (isalpha(c)) t = c, c = getchar_unlocked();
    }

    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct Node {
    int max_x = -1;
    set<pii> x_and_id;
};

struct Command {
    explicit Command(char type, int x, int y, int id) : type(type), x(x), y(y),
                                                        id(id) {}

    explicit Command(char type, int id) : type(type), id(id) {}

    char type;
    int x, y;
    int id;
};

vector<int> decretization(vector<int> A) {
    vector<int> result(A);
    sort(A.begin(), A.end());
    auto iter = unique(A.begin(), A.end());
    for (auto &i : result) {
        i = lower_bound(A.begin(), iter, i) - A.begin();
    }
    return result;
}

vector<Node> block;
vector<Command> commands;
vector<pii> students;

int main() {

    int n, x, y, id;
    char op;
    vector<int> A, B;
    // start students' id from 1 by padding an empty slot
    A.emplace_back(0);
    B.emplace_back(0);
    students.emplace_back(pii{});
    int id_counter = 1;
    IO::read(n);
    while (n--) {
        IO::read_alpha(op);
        if (op == 'D') {
            IO::read(x, y);
            A.emplace_back(x);
            B.emplace_back(y);
            commands.emplace_back(Command('D', x, y, id_counter));
            students.emplace_back(make_pair(x, y));
            ++id_counter;
        } else {
            IO::read(id);
            commands.emplace_back(Command('C', id));
        }
    }
    A = decretization(A);
    B = decretization(B);
    // update 'commands' after decretization
    int index = 1;
    for (auto &i : commands) {
        if (i.type == 'D') {
            i.x = A.at(index);
            i.y = B.at(index);
            ++index;
        }
    }
    // update 'students' after decretization
    for (size_t i = 1; i != students.size(); ++i) {
        students.at(i).first = A.at(i);
        students.at(i).second = B.at(i);
    }

    // establish the block
    int blocks = static_cast<int>(A.size()) - 1;
    block.resize(blocks + 1);
    bool have_ans;
    int current_max_y = -1;
    // read commands again
    for (auto &i : commands) {
        // insert
        if (i.type == 'D') {
            block.at(i.y).x_and_id.insert({i.x, i.id});
            block.at(i.y).max_x = max(block.at(i.y).max_x, i.x);
            current_max_y = max(current_max_y, i.y);
        }
        // query
        else {
            x = students.at(i.id).first;
            y = students.at(i.id).second;
            have_ans = false;
            // Scan: sqrt(n), maintain a maximal of y to avoid scanning the whole block
            for (int j = y; j <= current_max_y; ++j) {
                if (j == y) {
                    if (block.at(j).max_x >
                        x) {    // > x to avoid choosing itself
                        IO::writeln(
                                block.at(j).x_and_id.upper_bound(
                                        {x, INF})->second);
                        have_ans = true;
                        break;
                    }
                } else {
                    if (block.at(j).max_x >= x) {
                        IO::writeln(
                                block.at(j).x_and_id.lower_bound(
                                        {x, 0})->second);
                        have_ans = true;
                        break;
                    }
                }
            }
            if (!have_ans) {
                puts("NE");
            }
        }
    }
    return 0;
}