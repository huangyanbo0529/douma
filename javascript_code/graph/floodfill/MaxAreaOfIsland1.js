export class MaxAreaOfIsland1 {

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

        let res = 0
        for (let row = 0; row < this.rows; row++) {
            for (let col = 0; col < this.cols; col++) {
                if (grid[row][col] == 1) {
                    res = Math.max(this.dfs(row, col), res)
                }
            }
        }
        return res
    }

    dfs(row, col) {
        this.grid[row][col] = 0
        let res = 1
        for (const dir of this.directions) {
            const nextRow = row + dir[0]
            const nextCol = col + dir[1]
            if (this.inArea(nextRow, nextCol)
                && this.grid[nextRow][nextCol] == 1) {
                res += this.dfs(nextRow, nextCol)
            }
        }
        return res
    }

    inArea(row, col) {
        return row >= 0 && row < this.rows && col >= 0 && col < this.cols
    }

}

