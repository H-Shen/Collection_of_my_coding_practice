#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cstdint>

using ll = long long;
static constexpr ll MOD = 1'000'000'007;
static constexpr ll INV2 = (MOD + 1) / 2;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N, T;
    ll A, B, C, t0;
    std::cin >> N >> T;
    std::cin >> A >> B >> C >> t0;

    // Sequence u_i in [0, C-1], with u0 = t0-1, and u_i = (A*(u_{i-1}+1) + B) % C - 1 + 1? We adjust directly
    // We'll generate u_i = t_i - 1
    ll u = t0 - 1;
    std::vector<int> seen(C, -1);
    std::vector<ll> seq;
    seq.reserve(std::min<ll>(C, N));

    ll idx = 0, start_cycle = -1;
    while (idx < N) {
        if (seen[u] >= 0) {
            start_cycle = seen[u];
            break;
        }
        seen[u] = static_cast<int>(idx);
        seq.push_back(u);
        ++idx;
        if (idx == N) break;
        ll next = (A * (u + 1) + B) % C;
        u = next;
    }

    // Count occurrences of each time = u+1
    std::vector<ll> count(C + 1, 0);
    if (idx == N) {
        // No cycle within N
        for (ll v : seq) count[v + 1]++;
    } else {
        // prefix [0, start_cycle), cycle [start_cycle, idx)
        ll pre = start_cycle;
        ll cycle_len = idx - start_cycle;
        // prefix
        for (ll i = 0; i < pre; ++i) count[seq[i] + 1]++;
        // full cycles
        ll rem = N - pre;
        ll cycles = rem / cycle_len;
        ll tail = rem % cycle_len;
        for (ll i = start_cycle; i < idx; ++i) {
            count[seq[i] + 1] += cycles;
        }
        // remainder
        for (ll i = start_cycle; i < start_cycle + tail; ++i) {
            count[seq[i] + 1]++;
        }
    }

    // Now pick tasks in ascending time order
    ll solved = 0;
    ll sum_time = 0;
    ll penalty = 0;

    for (int t = 1; t <= C; ++t) {
        ll f = count[t];
        if (f == 0) continue;
        // max we can take so that sum_time + t*x <= T
        ll max_take = (T >= sum_time ? (T - sum_time) / t : 0);
        ll take = std::min<ll>(f, max_take);
        if (take <= 0) break;
        // penalty increase = take * sum_time + t * (take*(take+1)/2)
        ll S_mod = sum_time % MOD;
        ll take_mod = take % MOD;
        ll term1 = (take_mod * S_mod) % MOD;
        ll term2 = ( (take_mod * ((take + 1) % MOD)) % MOD * INV2 ) % MOD;
        term2 = (term2 * (t % MOD)) % MOD;
        penalty = (penalty + term1 + term2) % MOD;

        // update
        sum_time += take * t;
        solved += take;
        if (take < f) break;
    }

    std::cout << solved << " " << penalty << '\n';
    return 0;
}
