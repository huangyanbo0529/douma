

export class CCMaxCount {
    constructor(g) {
        this.g = g
        this.visited = new Array(g.getV()).fill(false)
        this.maxVertexNum = 0

        for (let v = 0; v < g.getV(); v++) {
            if (!this.visited[v]) {
                this.maxVertexNum = Math.max(this.dfs(v), this.maxVertexNum)
            }
        }
    }

    dfs(v) {
        this.visited[v] = true
        let res = 1
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                res += this.dfs(w)
            }
        }
        return res
    }

    getMaxVertexNum() {
        return this.maxVertexNum
    }
}