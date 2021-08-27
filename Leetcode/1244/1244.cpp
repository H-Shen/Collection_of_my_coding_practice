constexpr int MAXN = 1e4+5;
constexpr int INF = 0x3f3f3f3f;

class Leaderboard {
private:
    int A[MAXN];
    multiset<int, greater<> > m;
public:
    Leaderboard() {
        memset(A, 0x3f, sizeof A);
    }
    
    void addScore(int playerId, int score) {
        if (A[playerId] == INF) {
            A[playerId] = score;
        }
        else {
            m.erase(m.find(A[playerId]));
            A[playerId] += score;
        }
        m.insert(A[playerId]);
    }
    
    int top(int K) {
        int sum = 0;
        auto iter = m.begin();
        for (int i = 0; i < K; ++i) {
            sum += *iter;
            ++iter;
        }
        return sum;
    }
    
    void reset(int playerId) {
        m.erase(m.find(A[playerId]));
        A[playerId] = INF;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */