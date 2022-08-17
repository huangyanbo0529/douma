

export class CycleDetection {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.hasCycle = false
        this.visited = new Array(g.getV()).fill(false)
        this.isOnPath = new Array(g.getV()).fill(false)

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!this.visited[v]) {
                if (this.dfs(v)) {
                    this.hasCycle = true
                    break
                }
            }
        }
    }

    dfs(v) {
        this.visited[v] = true
        this.isOnPath[v] = true
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                // 后面的循环就可以不执行了
                if (this.dfs(w)) return true
            } else { // 否则，w 顶点已经被访问
                if (this.isOnPath[w]) return true
            }
        }
        this.isOnPath[v] = false
        return false
    }

    getHasCycle() {
        return this.hasCycle
    }
}