
export class CC1 {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.ccCount = 0
        // 记录每个顶点所属的连通分量
        // -1 表示不属于任何的连通分量，其实这个顶点还表示没有访问
        this.visited = new Array(g.getV()).fill(-1)

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (this.visited[v] == -1) {
                this.ccCount++
                this.dfs(v, this.ccCount)
            }
        }
    }

    dfs(v, ccId) {
        this.visited[v] = ccId
        for (const w of this.g.adj(v)) {
            if (this.visited[w] == -1) this.dfs(w, ccId)
        }
    }

    getCCCount() {
        return this.ccCount
    }

    components() {
        const res = new Array(this.ccCount)
        for (let i = 0; i < this.ccCount; i++) {
            res[i] = []
        }
        for (let v = 0; v < this.g.getV(); v++) {
            const cc = this.visited[v]
            res[cc - 1].push(v)
        }
        return res
    }

    isConnected(v, w) {
        this.validateVertex(v)
        this.validateVertex(w)
        return this.visited[v] == this.visited[w]
    }

    validateVertex(v) {
        if (v < 0 && v >= this.g.getV()) {
            throw new Error("顶点不合法，超出范围")
        }
    }
}