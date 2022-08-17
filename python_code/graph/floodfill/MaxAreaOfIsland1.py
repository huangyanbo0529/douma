class MaxAreaOfIsland1:

    def __init__(self):
        self.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        self.rows = self.cols = 0
        self.grid = []

    def maxAreaOfIsland(self, grid) -> int:
        if grid is None:
            return 0

        self.rows = len(grid)
        if self.rows == 0:
            return 0
        self.cols = len(grid[0])
        self.grid = grid

        res = 0
        for row in range(self.rows):
            for col in range(self.cols):
                if self.grid[row][col] == 1:
                    res = max(self.dfs(row, col), res)
        return res

    def dfs(self, row, col):
        self.grid[row][col] = 0
        res = 1
        for dir in self.directions:
            nextRow = row + dir[0]
            nextCol = col + dir[1]
            if self.inArea(nextRow, nextCol) and self.grid[nextRow][nextCol] == 1:
                res += self.dfs(nextRow, nextCol)
        return res

    def inArea(self, row, col):
        return 0 <= row < self.rows and 0 <= col < self.cols


if __name__ == '__main__':
    grid = [
        [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    ]
    maxAreaOfIsland = MaxAreaOfIsland1()
    print(maxAreaOfIsland.maxAreaOfIsland(grid))
