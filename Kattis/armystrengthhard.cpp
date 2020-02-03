// https://open.kattis.com/problems/armystrengthhard
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

  int t;
  ll n_g, n_m;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &n_g, &n_m);
    deque<ll> G(n_g);
    for (auto &i : G) {
      scanf("%lld", &i);
    }
    sort(G.begin(), G.end());
    deque<ll> M(n_m);
    for (auto &i : M) {
      scanf("%lld", &i);
    }
    sort(M.begin(), M.end());
    while (!G.empty() && !M.empty()) {
      if (G.front() < M.front()) {
        G.pop_front();
      } else if (G.front() > M.front()) {
        M.pop_front();
      } else {
        M.pop_front();
      }
    }
    if (G.empty() && !M.empty()) {
      printf("MechaGodzilla\n");
    } else if (!G.empty() && M.empty()) {
      printf("Godzilla\n");
    } else {
      printf("uncertain\n");
    }
  }
  return 0;
}
