# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1

class Board:
    def checkWon(self, board):
        # write code here
        a = board + zip(*board)
        for i in a:
            if len(set(i)) == 1 and 1 in i:
                return True
        if board[0][0] == board[1][1] == board[2][2] == 1 or board[2][0] == board[1][1] == board[0][2] == 1:
            return True
        return False