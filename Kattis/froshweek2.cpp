// https://open.kattis.com/problems/froshweek2
#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int no_music, task;
    cin >> task >> no_music;
    vector<int> Task(task);
    vector<int> No_music(no_music);
    for (auto &&i : Task) cin >> i;
    for (auto &&i : No_music) cin >> i;
    sort(Task.begin(), Task.end());
    sort(No_music.begin(), No_music.end());

    int cnt = 0;
    int j = no_music - 1;

    for (int i = task - 1; i >= 0; --i) {
        if (No_music[j] >= Task[i]) {
            ++cnt;
            --j;
            if (j < 0) {
                break;
            }
        }
    }
    cout << cnt << endl;
}
