export class MaxAreaOfIsland {

    constructor() {
        this.directions = [
            [-1, 0], [1, 0], [0, -1], [0, 1],
        ]
    }

    maxAreaOfIsland(grid) {
        if (grid == null) return 0

        this.rows = grid.length
        if (this.rows == 0) return 0
        this.cols = grid[0].length
        this.grid = grid

        // 1. 建图
        this.graph = this.constructGraph()

        // 2. 求解最大联通分量的顶点数
        this.visited = new Array(this.graph.length).fill(false)
        let res = 0
        for (let v = 0; v < this.graph.length; v++) {
            const row = Math.floor(v / this.cols)
            const col = v % this.cols
            if (!this.visited[v] && grid[row][col] == 1) {
                res = Math.max(this.dfs(v), res)
            }
        }
        return res
    }

    dfs(v) {
        this.visited[v] = true
        let res = 1
        for (const w of this.graph[v]) {
            if (!this.visited[w]) {
                res += this.dfs(w)
            }
        }
        return res
    }

    constructGraph() {
        const g = new Array(this.rows * this.cols).fill(0)
        for (let v = 0; v < g.length; v++) {
            g[v] = new Set()
        }

        for (let v = 0; v < g.length; v++) {
            const row = Math.floor(v / this.cols)
            const col = v % this.cols
            if (this.grid[row][col] == 1) {
                for (const dir of this.directions) {
                    const nextRow = row + dir[0]
                    const nextCol = col + dir[1]
                    if (this.inArea(nextRow, nextCol)
                        && this.grid[nextRow][nextCol] == 1) {
                        const w = nextRow * this.cols + nextCol
                        g[v].add(w)
                        g[w].add(v)
                    }
                }
            }
        }

        return g
    }

    inArea(row, col) {
        return row >= 0 && row < this.rows && col >= 0 && col < this.cols
    }

}

