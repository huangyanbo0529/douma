export class MaxAreaOfIsland3 {

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
                    let currOnes = 0
                    const queue = []
                    queue.push([row, col])
                    // bug 修复，每次将元素 push 到栈中都要将其设置为 0
                    grid[row][col] = 0
                    while (queue.length) {
                        const curr = queue.shift()
                        const currRow = curr[0], currCol = curr[1]
                        currOnes++
                        for (const dir of this.directions) {
                            const nextRow = currRow + dir[0]
                            const nextCol = currCol + dir[1]
                            if (this.inArea(nextRow, nextCol)
                                && this.grid[nextRow][nextCol] == 1) {
                                queue.push([nextRow, nextCol])
                                // bug 修复，每次将元素 push 到栈中都要将其设置为 0
                                grid[nextRow][nextCol] = 0
                            }
                        }
                    }
                    res = Math.max(res, currOnes)
                }
            }
        }
        return res
    }

    inArea(row, col) {
        return row >= 0 && row < this.rows && col >= 0 && col < this.cols
    }

}

