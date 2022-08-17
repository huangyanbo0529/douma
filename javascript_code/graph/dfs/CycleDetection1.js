

export class CycleDetection1 {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.hasCycle = false
        this.visited = new Array(g.getV()).fill(false)

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!this.visited[v]) {
                if (this.dfs(v, v)) {
                    this.hasCycle = true
                    break
                }
            }
        }
    }

    dfs(v, prev) {
        this.visited[v] = true
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                // 后面的循环就可以不执行了
                if (this.dfs(w, v)) return true
            } else { // 否则，w 顶点已经被访问
                // 如果 w 不是 v 的前一个节点的话，那么就存在环
                if (w != prev) return true
            }
        }
        return false
    }

    getHasCycle() {
        return this.hasCycle
    }
}