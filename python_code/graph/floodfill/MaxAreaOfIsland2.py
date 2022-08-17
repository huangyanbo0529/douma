class MaxAreaOfIsland2:

    def __init__(self):
        self.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        self.rows = self.cols = 0

    def maxAreaOfIsland(self, grid) -> int:
        if grid is None:
            return 0

        self.rows = len(grid)
        if self.rows == 0:
            return 0
        self.cols = len(grid[0])

        res = 0
        for row in range(self.rows):
            for col in range(self.cols):
                if grid[row][col] == 1:
                    currOnes = 0
                    stack = [[row, col]]
                    # bug 修复，每次将元素 push 到栈中都要将其设置为 0
                    grid[row][col] = 0
                    while len(stack):
                        curr = stack.pop()
                        currRow, currCol = curr[0], curr[1]
                        currOnes += 1
                        for dir in self.directions:
                            nextRow = currRow + dir[0]
                            nextCol = currCol + dir[1]
                            if self.inArea(nextRow, nextCol) and grid[nextRow][nextCol] == 1:
                                stack.append([nextRow, nextCol])
                                # bug 修复，每次将元素 push 到栈中都要将其设置为 0
                                grid[nextRow][nextCol] = 0
                    res = max(res, currOnes)
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
    maxAreaOfIsland = MaxAreaOfIsland2()
    print(maxAreaOfIsland.maxAreaOfIsland(grid))
