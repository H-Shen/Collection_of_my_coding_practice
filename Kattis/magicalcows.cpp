#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N, M;
    cin >> C >> N >> M;
    vector<int> c(N), d(M);
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    for(int j = 0; j < M; j++){
        cin >> d[j];
    }

    // Precompute floor(log2(C/c[i])) for each farm
    vector<int> T(N);
    for(int i = 0; i < N; i++){
        // compute largest t with (1<<t) * c[i] <= C
        // that's floor(log2(C / c[i]))
        int v = C / c[i];
        int t = 0;
        // find highest set-bit in v
        while((1 << (t+1)) <= v) ++t;
        T[i] = t;
    }

    // Precompute powers of two up to 50
    static long long pw2[51];
    pw2[0] = 1;
    for(int i = 1; i <= 50; i++){
        pw2[i] = pw2[i-1] << 1;
    }

    // Answer each query
    for(int j = 0; j < M; j++){
        long long day = d[j];
        long long ans = 0;
        for(int i = 0; i < N; i++){
            if(day <= T[i]){
                ans += 1;
            } else {
                ans += pw2[ day - T[i] ];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
