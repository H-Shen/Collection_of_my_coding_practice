// https://open.kattis.com/problems/iwannabe
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

struct Pokenom {
    ll attack;
    ll defense;
    ll health;
    int id;
};

int main() {

    int N, K;
    scanf("%d %d", &N, &K);
    vector<Pokenom> A(static_cast<size_t>(N));
    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld %lld", &A.at(i).attack, &A.at(i).defense, &A.at(i).health);
        A.at(i).id = i;
    }
    unordered_set<int> uniqPokenom;
    // sort by attack
    sort(A.begin(), A.end(), [](const Pokenom &lhs, const Pokenom &rhs) {
        return (lhs.attack > rhs.attack);
    });
    for (int i = 0; i < K; ++i) {
        uniqPokenom.insert(A.at(i).id);
    }
    // sort by defense
    sort(A.begin(), A.end(), [](const Pokenom &lhs, const Pokenom &rhs) {
        return (lhs.defense > rhs.defense);
    });
    for (int i = 0; i < K; ++i) {
        uniqPokenom.insert(A.at(i).id);
    }
    // sort by health
    sort(A.begin(), A.end(), [](const Pokenom &lhs, const Pokenom &rhs) {
        return (lhs.health > rhs.health);
    });
    for (int i = 0; i < K; ++i) {
        uniqPokenom.insert(A.at(i).id);
    }
    // output
    printf("%lu\n", uniqPokenom.size());

    return 0;
}
