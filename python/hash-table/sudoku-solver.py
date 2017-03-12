class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def isVaild(x, y):
            tmp = board[x][y]
            board[x][y] = 'D'
            for i in range(9):
                if board[i][y] == tmp:
                    return False
                if board[x][i] == tmp:
                    return False

            for i in range(3):
                for j in range(3):
                    if board[(x // 3) * 3 + i][(y // 3) * 3 + j] == tmp:
                        return False

            board[x][y] = tmp
            return True

        def dfs(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] != '.':
                        continue
                    for val in '123456789':
                        board[i][j] = val
                        if isVaild(i, j) and dfs(board):
                            return True
                        board[i][j] = '.'
                    return False
            return True

        dfs(board)
