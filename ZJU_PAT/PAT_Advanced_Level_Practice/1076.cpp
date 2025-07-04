#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, L;
    std::cin >> N >> L;
    std::vector<std::vector<int>> followers(N + 1);

    // Input: for each user i, list of users they follow
    for (int i = 1; i <= N; ++i) {
        int M;
        std::cin >> M;
        while (M--) {
            int v;
            std::cin >> v;
            // i follows v, so v has follower i
            followers[v].push_back(i);
        }
    }

    int K;
    std::cin >> K;
    while (K--) {
        int user;
        std::cin >> user;

        std::vector<bool> visited(N + 1, false);
        std::queue<std::pair<int,int>> q;
        visited[user] = true;

        // start from direct followers at level 1
        q.push({user, 0});
        int count = 0;

        while (!q.empty()) {
            auto [u, lvl] = q.front();
            q.pop();
            if (lvl == L) continue;
            for (int f : followers[u]) {
                if (!visited[f]) {
                    visited[f] = true;
                    ++count;
                    q.push({f, lvl + 1});
                }
            }
        }

        std::cout << count << "\n";
    }
    return 0;
}
