

export class CycleDetection {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.hasCycle = false
        this.visited = new Array(g.getV()).fill(false)

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!this.visited[v]) this.dfs(v, v)
        }
    }

    dfs(v, prev) {
        this.visited[v] = true
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                this.dfs(w, v)
            } else { // 否则，w 顶点已经被访问
                // 如果 w 不是 v 的前一个节点的话，那么就存在环
                if (w != prev) this.hasCycle = true
            }
        }
    }

    getHasCycle() {
        return this.hasCycle
    }
}