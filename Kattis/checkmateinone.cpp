// https://open.kattis.com/problems/checkmateinone
//
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

// Check whether (r,c) is on the board.
inline bool inBoard(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

// Returns true if the line between (r1,c1) and (r2,c2) is clear of blockers.
// (r1,c1) and (r2,c2) are assumed to lie on the same row or same column.
// Our king (at (kr,kc)) is the only potential blocker.
bool lineClear(int r1, int c1, int r2, int c2, int kr, int kc) {
    if(r1 == r2) {
        int row = r1;
        int start = min(c1, c2) + 1, end = max(c1, c2) - 1;
        for (int c = start; c <= end; c++) {
            if(row == kr && kc == c) return false;
        }
        return true;
    } else if(c1 == c2) {
        int col = c1;
        int start = min(r1, r2) + 1, end = max(r1, r2) - 1;
        for (int r = start; r <= end; r++) {
            if(col == kc && kr == r) return false;
        }
        return true;
    }
    return false; // Not collinear (should not happen for a rook)
}

// Check if the rook (at (rr,rc)) delivers check to the enemy king at (er,ec),
// given that our king is at (kr,kc).
bool rookDeliversCheck(int rr, int rc, int er, int ec, int kr, int kc) {
    if(rr == er || rc == ec)
        return lineClear(rr, rc, er, ec, kr, kc);
    return false;
}

// Given a candidate square (cr,cc) that the enemy king might move to, check if that square is “safe”.
// “Safe” means: the square is on board, it is not adjacent to our king, and it is not attacked by the rook.
// (Note: if (cr,cc) equals the rook’s square then that move means the enemy king would capture the rook,
// and that move is legal if (cr,cc) is not adjacent to our king.)
bool safeForEnemyKing(int cr, int cc, int rr, int rc, int kr, int kc) {
    if(!inBoard(cr,cc)) return false;
    // The enemy king cannot move to a square adjacent to our king.
    if(abs(cr - kr) <= 1 && abs(cc - kc) <= 1)
        return false;
    // If the square is the rook’s square, that move would capture the rook.
    if(cr == rr && cc == rc) return true;
    // Otherwise, if the square lies in the same row or column as the rook,
    // check whether the rook’s attack is blocked by our king.
    if(cr == rr) { // same row
        int start = min(cc, rc) + 1, end = max(cc, rc) - 1;
        if(kr == cr && kc >= start && kc <= end)
            ; // our king blocks the rook’s attack here.
        else
            return false; // candidate is attacked by the rook.
    } else if(cc == rc) { // same column
        int start = min(cr, rr) + 1, end = max(cr, rr) - 1;
        if(kc == cc && kr >= start && kr <= end)
            ; // blocked by our king.
        else
            return false;
    }
    // Otherwise, candidate is not directly attacked by the rook.
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // Read the 8x8 board.
    vector<string> board(8);
    for (int i = 0; i < 8; i++){
        getline(cin, board[i]);
    }

    // Locate our pieces.
    int rook_r = -1, rook_c = -1;
    int king_r = -1, king_c = -1;
    int enemy_r = -1, enemy_c = -1;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            char ch = board[i][j];
            if(ch == 'R'){
                rook_r = i; rook_c = j;
            } else if(ch == 'K'){
                king_r = i; king_c = j;
            } else if(ch == 'k'){
                enemy_r = i; enemy_c = j;
            }
        }
    }
    // (We assume the board is valid and exactly one R, one K, and one k exist.)

    // Enumerate all legal moves for our rook.
    // The rook moves in the four cardinal directions until it hits a blocking piece.
    vector<pair<int,int>> rookMoves;
    int dirs[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    for(auto &d : dirs) {
        int dr = d[0], dc = d[1];
        int nr = rook_r, nc = rook_c;
        while(true) {
            nr += dr; nc += dc;
            if(!inBoard(nr, nc)) break;
            // The rook cannot move onto a square occupied by our king or the enemy king.
            if((nr == king_r && nc == king_c) || (nr == enemy_r && nc == enemy_c))
                break;
            // This square is empty and reachable.
            rookMoves.emplace_back(nr, nc);
        }
    }

    bool mateFound = false;
    // Try every legal rook move.
    for(auto &mv : rookMoves) {
        int newR_r = mv.first, newR_c = mv.second;
        // After our rook moves, check if it gives check to the enemy king.
        if(!rookDeliversCheck(newR_r, newR_c, enemy_r, enemy_c, king_r, king_c))
            continue;
        // Now, check every one of the enemy king's possible moves (the 8 adjacent squares).
        bool enemyCanEscape = false;
        for (int dr = -1; dr <= 1; dr++){
            for (int dc = -1; dc <= 1; dc++){
                if(dr == 0 && dc == 0) continue; // enemy king must move.
                int cand_r = enemy_r + dr;
                int cand_c = enemy_c + dc;
                if(safeForEnemyKing(cand_r, cand_c, newR_r, newR_c, king_r, king_c)) {
                    enemyCanEscape = true;
                    break;
                }
            }
            if(enemyCanEscape) break;
        }
        if(!enemyCanEscape) { // enemy king is in check and has no legal moves.
            mateFound = true;
            break;
        }
    }
    cout << (mateFound ? "Yes" : "No") << "\n";
    return 0;
}
