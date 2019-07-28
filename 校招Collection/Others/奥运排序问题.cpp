// https://www.nowcoder.com/practice/100a4376cafc439b86f5f8791fb461f3

#include <cstdio>

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Fraction {
    int x, y;
};

struct Country {

    int id = -1;
    int goldenPrize = -1;
    int prize = -1;
    int people = -1;

    Fraction golden2people{};
    Fraction prize2people{};

    int rankByGoldenPrize = -1;
    int rankByPrize = -1;
    int rankByGolden2People = -1;
    int rankByPrize2People = -1;

};

inline bool cmpFraction(const Fraction &a, const Fraction &b) {
    return (a.x * b.y - a.y * b.x > 0);
}

inline bool fractionEqual(const Fraction &a, const Fraction &b) {
    return (a.x * b.y - a.y * b.x == 0);
}

inline bool cmp0(const Country &a, const Country &b) {
    return (a.goldenPrize > b.goldenPrize);
}

inline bool cmp1(const Country &a, const Country &b) {
    return (a.prize > b.prize);
}

inline bool cmp2(const Country &a, const Country &b) {
    return cmpFraction(a.golden2people, b.golden2people);
}

inline bool cmp3(const Country &a, const Country &b) {
    return cmpFraction(a.prize2people, b.prize2people);
}

inline bool cmpById(const Country &a, const Country &b) {
    return (a.id < b.id);
}

void fixRank(vector<Country> &A, int controlNum, int len) {

    int lastItem, lastRank, j;
    Fraction lastItemFraction{};

    switch (controlNum) {

        //fix by golden prize rank
        case (0) : {
            lastItem = A[0].goldenPrize;
            lastRank = A[0].rankByGoldenPrize;

            for (j = 1; j < len; j++) {
                if (A[j].goldenPrize == lastItem)
                    A[j].rankByGoldenPrize = lastRank;
                else {
                    lastItem = A[j].goldenPrize;
                    lastRank = A[j].rankByGoldenPrize;
                }
            }
            break;
        }

            //fix by prize rank
        case (1) : {
            lastItem = A[0].prize;
            lastRank = A[0].rankByPrize;
            for (j = 1; j < len; j++) {
                if (A[j].prize == lastItem)
                    A[j].rankByPrize = lastRank;
                else {
                    lastItem = A[j].prize;
                    lastRank = A[j].rankByPrize;
                }
            }
            break;
        }

            //fix by golden2people rank
        case (2) : {
            lastItemFraction = A[0].golden2people;
            lastRank = A[0].rankByGolden2People;
            for (j = 1; j < len; j++) {
                if (fractionEqual(A[j].golden2people, lastItemFraction))
                    A[j].rankByGolden2People = lastRank;
                else {
                    lastItemFraction = A[j].golden2people;
                    lastRank = A[j].rankByGolden2People;
                }
            }
            break;
        }

            //fix by prize2people rank
        case (3) : {
            lastItemFraction = A[0].prize2people;
            lastRank = A[0].rankByPrize2People;
            for (j = 1; j < len; j++) {
                if (fractionEqual(A[j].prize2people, lastItemFraction))
                    A[j].rankByPrize2People = lastRank;
                else {
                    lastItemFraction = A[j].prize2people;
                    lastRank = A[j].rankByPrize2People;
                }
            }
            break;
        }

        default : {
            break;
        }
    }
}

int main() {

    int N, M, i, tempVal;

    while (scanf("%d %d", &N, &M) != EOF) {

        vector<Country> A(static_cast<unsigned long>(N));
        for (i = 0; i < N; i++) {
            A[i].id = i;
            scanf("%d %d %d", &A[i].goldenPrize, &A[i].prize, &A[i].people);
            A[i].golden2people.x = A[i].goldenPrize;
            A[i].golden2people.y = A[i].people;
            A[i].prize2people.x = A[i].prize;
            A[i].prize2people.y = A[i].people;
        }

        vector<Country> Query(static_cast<unsigned long>(M));
        vector<int> queryNumLog(static_cast<unsigned long>(M));

        for (i = 0; i < M; i++) {
            scanf("%d", &tempVal);
            Query[i] = A[tempVal];
            queryNumLog[i] = tempVal;
        }

        sort(Query.begin(), Query.end(), cmp0);
        for (i = 0; i < M; i++) {
            Query[i].rankByGoldenPrize = i + 1;
        }
        fixRank(Query, 0, M);

        sort(Query.begin(), Query.end(), cmp1);
        for (i = 0; i < M; i++) {
            Query[i].rankByPrize = i + 1;
        }
        fixRank(Query, 1, M);

        sort(Query.begin(), Query.end(), cmp2);
        for (i = 0; i < M; i++) {
            Query[i].rankByGolden2People = i + 1;
        }
        fixRank(Query, 2, M);

        sort(Query.begin(), Query.end(), cmp3);
        for (i = 0; i < M; i++) {
            Query[i].rankByPrize2People = i + 1;
        }
        fixRank(Query, 3, M);

        sort(Query.begin(), Query.end(), cmpById);
        unordered_map<int, Country> reSortMap;
        for (i = 0; i < M; i++) {
            reSortMap[Query[i].id] = Query[i];
        }
        vector<Country> reSort(static_cast<unsigned long>(M));
        for (i = 0; i < M; i++) {
            reSort[i] = reSortMap[queryNumLog[i]];

        }

        // FINAL SORTING
        for (i = 0; i < M; i++) {

            vector<int> rankLog(4);

            rankLog[0] = reSort[i].rankByGoldenPrize;
            rankLog[1] = reSort[i].rankByPrize;
            rankLog[2] = reSort[i].rankByGolden2People;
            rankLog[3] = reSort[i].rankByPrize2People;

            int minRank = *min_element(rankLog.begin(), rankLog.end());

            if (rankLog[0] == minRank) {
                printf("%d:1\n", minRank);
            } else if (rankLog[1] == minRank) {
                printf("%d:2\n", minRank);
            } else if (rankLog[2] == minRank) {
                printf("%d:3\n", minRank);
            } else {
                printf("%d:4\n", minRank);
            }
        }
        printf("\n");
    }
    return 0;
}