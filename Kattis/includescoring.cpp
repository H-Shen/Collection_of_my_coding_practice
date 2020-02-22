// https://open.kattis.com/problems/includescoring
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Contestant {
    int s, p, f;
    int score;
    int id;
    int people_with_the_same_rank = 1;
};

bool cmp0(const Contestant &lhs, const Contestant &rhs) {
    if (lhs.s == rhs.s) {
        if (lhs.p == rhs.p) {
            return (lhs.f < rhs.f);
        }
        return (lhs.p < rhs.p);
    }
    return (lhs.s > rhs.s);
}

bool cmp1(const Contestant &lhs, const Contestant &rhs) {
    return (lhs.id < rhs.id);
}

unordered_map<int, int> rank2score;

void pre() {
    vector<int> temp_vec = {100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int counter = 1;
    for (const auto &i : temp_vec) {
        rank2score[counter++] = i;
    }
}

int main() {

    pre();
    int n;
    scanf("%d", &n);
    vector<Contestant> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &A.at(i).s, &A.at(i).p, &A.at(i).f, &A.at(i).score);
        A.at(i).id = i;
    }
    sort(A.begin(), A.end(), cmp0);

    int current_s = A.front().s;
    int current_p = A.front().p;
    int current_f = A.front().f;
    int counter = 1;
    for (int i = 1; i < n; ++i) {
        if (A.at(i).s == current_s && A.at(i).p == current_p && A.at(i).f == current_f) {
            ++counter;
        } else {
            for (int j = 1; j <= counter; ++j) {
                A.at(i - j).people_with_the_same_rank = counter;
            }
            counter = 1;
            current_s = A.at(i).s;
            current_p = A.at(i).p;
            current_f = A.at(i).f;
        }
    }
    if (counter > 1) {
        for (int j = 1; j <= counter; ++j) {
            A.at(n - j).people_with_the_same_rank = counter;
        }
    }
    int index = 0;
    int current_rank = 1;
    while (index < n) {
        if (A.at(index).people_with_the_same_rank == 1) {
            A.at(index).score += rank2score[current_rank];
            ++current_rank;
            ++index;
        } else {
            int avg_score = 0;
            int item_counter = 0;
            for (int i = 1; i <= A.at(index).people_with_the_same_rank; ++i) {
                avg_score += rank2score[current_rank];
                ++current_rank;
                ++item_counter;
            }
            if (avg_score % item_counter == 0) {
                avg_score /= item_counter;
            } else {
                avg_score = static_cast<int>(1.0 * avg_score / item_counter) + 1;
            }
            for (int i = 1; i <= A.at(index).people_with_the_same_rank; ++i) {
                A.at(index + i - 1).score += avg_score;
            }
            index += A.at(index).people_with_the_same_rank;
        }
    }
    sort(A.begin(), A.end(), cmp1);

    for (const auto &i : A) {
        printf("%d\n", i.score);
    }

    return 0;
}
