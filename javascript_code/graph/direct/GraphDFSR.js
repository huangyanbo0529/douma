

export class GraphDFSR {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.res = []
        this.visited = new Array(g.getV()).fill(false)

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!this.visited[v]) this.dfs(v)
        }
    }

    dfs(v) {
        this.res.push(v)
        this.visited[v] = true
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) this.dfs(w)
        }
    }

    getRes() {
        return this.res
    }
}