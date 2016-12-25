class Solution(object):
    def islandPerimeter(self, grid):
        row = len(grid)
        col = len(grid[0]) if row else 0
        p = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    continue
                p += 4

                if i > 0 and grid[i-1][j]:
                    p -= 2
                if j > 0 and grid[i][j-1]:
                    p -= 2

        return p
