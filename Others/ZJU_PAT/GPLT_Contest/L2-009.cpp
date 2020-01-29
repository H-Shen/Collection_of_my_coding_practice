#include <bits/stdc++.h>

using namespace std;

struct Person {
    int id;
    int total = 0;
    int packetCount = 0;
    double outputTotal;
};

bool cmp(const Person &a, const Person &b) {
    if (a.total == b.total) {
        if (a.packetCount == b.packetCount) {
            return (a.id < b.id);
        }
        return (a.packetCount > b.packetCount);
    }
    return (a.total > b.total);
}

int main() {
    unordered_map<int, Person> A;
    int n, i, j, tmp, id, money;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        A[i].id = i;
        unordered_set<int> tmpSave;
        for (j = 0; j < tmp; ++j) {
            scanf("%d %d", &id, &money);
            if (tmpSave.find(id) != tmpSave.end()) {
                continue;
            }
            tmpSave.insert(id);
            ++A[id].packetCount;
            A[id].id = id;
            A[id].total += money;
            A[i].total -= money;
        }
    }

    int len = A.size();
    i = 0;
    vector<Person> outputList(len);
    for (auto it = A.cbegin(); it != A.cend(); ++it) {
        outputList[i] = it->second;
        outputList[i].outputTotal = static_cast<double>(outputList[i].total) / 100.0;
        ++i;
    }
    sort(outputList.begin(), outputList.end(), cmp);
    for (const auto &p : outputList) {
        printf("%d %.2f\n", p.id, p.outputTotal);
    }
    return 0;
}
