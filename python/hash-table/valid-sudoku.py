class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(len(board)):
            d = {}
            for j in range(len(board[i])):
                if board[i][j] == '.':
                    continue
                if board[i][j] in d:
                    return False
                d[board[i][j]] = 1

        for j in range(len(board[0])):
            d = {}
            for i in range(len(board)):
                if board[i][j] == '.':
                    continue
                if board[i][j] in d:
                    return False
                d[board[i][j]] = 1

        for i in range(9):
            d = {}
            for j in range(9):
                row = (i // 3) * 3 + j // 3
                col = (i % 3) * 3 + j % 3
                if board[row][col] == '.':
                    continue
                if board[row][col] in d:
                    return False
                d[board[row][col]] = 1

        return True
