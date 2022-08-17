

export class BipartitionDetection {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.visited = new Array(g.getV()).fill(false)
        // -1 表示没有染颜色
        // 0 红色 1 蓝色
        this.colors = new Array(g.getV()).fill(-1)
        this.isBipartition = true

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!this.visited[v] && !this.dfs(v, 0)) {
                this.isBipartition = false
                break
            }
        }
    }

    dfs(v, color) {
        this.visited[v] = true
        this.colors[v] = color
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                // 如果 v 的颜色是 1，那么 w 的颜色就是 0
                // 如果 v 的颜色是 0，那么 w 的颜色就是 1
                if (!this.dfs(w, 1 - color)) return false
            } else if (this.colors[w] == this.colors[v]) {
                // 如果相邻顶点的颜色一样的话，则不是二分图
                return false
            }
        }
        return true
    }

    getIsBipartition() {
        return this.isBipartition
    }
}