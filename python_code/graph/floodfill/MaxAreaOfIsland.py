class MaxAreaOfIsland:

    def __init__(self):
        self.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        self.rows = self.cols = 0
        self.grid = []
        self.graph = []
        self.visited = []

    def maxAreaOfIsland(self, grid) -> int:
        if grid is None:
            return 0

        self.rows = len(grid)
        if self.rows == 0:
            return 0
        self.cols = len(grid[0])
        self.grid = grid

        # 1. 建图
        self.graph = self.constructGraph()

        # 2. 求解最大联通分量的顶点数
        self.visited = [False] * len(self.graph)
        res = 0
        for v in range(len(self.graph)):
            row = v // self.cols
            col = v % self.cols
            if not self.visited[v] and self.grid[row][col] == 1:
                res = max(self.dfs(v), res)
        return res

    def dfs(self, v):
        self.visited[v] = True
        res = 1
        for w in self.graph[v]:
            if not self.visited[w]:
                res += self.dfs(w)
        return res

    def constructGraph(self):
        g = [0] * (self.rows * self.cols)
        for v in range(len(g)):
            g[v] = set()
        for v in range(len(g)):
            row, col = v // self.cols, v % self.cols
            if self.grid[row][col] == 1:
                for dir in self.directions:
                    nextRow = row + dir[0]
                    nextCol = col + dir[1]
                    if self.inArea(nextRow, nextCol) and self.grid[nextRow][nextCol] == 1:
                        w = nextRow * self.cols + nextCol
                        g[v].add(w)
                        g[w].add(v)
        return g

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
    maxAreaOfIsland = MaxAreaOfIsland()
    print(maxAreaOfIsland.maxAreaOfIsland(grid))
