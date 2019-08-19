#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const int MAXN = 30;
char s[MAXN];

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a < eps) return 0;
    return 1;
}

struct Stu {
    string id;
    int p_score = -1;
    int mid_score = -1;
    int final_score = -1;
    int G = -1;
};

bool cmp(const Stu &a, const Stu &b) {
    if (a.G == b.G) {
        return (a.id < b.id);
    }
    return (a.G > b.G);
}

int main() {
    int p, m, n, tmp;
    scanf("%d %d %d", &p, &m, &n);
    getchar();
    string str;

    unordered_map<string, Stu> A;
    int i;
    for (i = 0; i < p; ++i) {
        scanf("%s %d", s, &tmp);
        str = s;
        A[str].id = s;
        A[str].p_score = tmp;
    }
    for (i = 0; i < m; ++i) {
        scanf("%s %d", s, &tmp);
        str = s;
        A[str].id = s;
        A[str].mid_score = tmp;
    }
    for (i = 0; i < n; ++i) {
        scanf("%s %d", s, &tmp);
        str = s;
        A[str].id = s;
        A[str].final_score = tmp;
    }

    vector<Stu> res;
    for (auto it = A.begin(); it != A.end(); ++it) {
        if (it->second.mid_score > it->second.final_score) {
            double tmpDouble = it->second.mid_score * 0.4 + it->second.final_score * 0.6;
            double tmpDD = tmpDouble - (int) tmpDouble;
            if (sgn(tmpDD - 0.5) >= 0) {
                it->second.G = (int) tmpDouble + 1;
            } else {
                it->second.G = (int) tmpDouble;
            }
        } else {
            it->second.G = it->second.final_score;
        }

        if (it->second.G >= 60 && it->second.p_score >= 200) {
            res.push_back(it->second);
        }
    }
    sort(res.begin(), res.end(), cmp);
    for (const auto &p : res)
        printf("%s %d %d %d %d\n", p.id.c_str(), p.p_score, p.mid_score, p.final_score, p.G);

    return 0;
}
