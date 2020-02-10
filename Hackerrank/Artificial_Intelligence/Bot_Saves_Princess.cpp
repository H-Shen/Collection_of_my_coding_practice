#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int m_i, m_j, p_i, p_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid.at(i).at(j) == 'm') {
                m_i = i;
                m_j = j;
            } else if (grid.at(i).at(j) == 'p') {
                p_i = i;
                p_j = j;
            }
        }
    }
    int gap_i = m_i - p_i;
    int gap_j = m_j - p_j;
    while (gap_i > 0) {
        --gap_i;
        printf("UP\n");
    }
    while (gap_i < 0) {
        ++gap_i;
        printf("DOWN\n");
    }
    while (gap_j > 0) {
        --gap_j;
        printf("LEFT\n");
    }
    while (gap_j < 0) {
        ++gap_j;
        printf("RIGHT\n");
    }
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}