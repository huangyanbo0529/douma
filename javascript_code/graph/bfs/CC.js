

export class CC {

    constructor(g) {
        this.g = g
        // 除了标记是否被访问过这个信息外，还记录每个节点所属的连通分量
        this.visited = new Array(g.getV()).fill(-1)
        this.ccCount = 0

        for (let v = 0; v < g.getV(); v++) {
            if (this.visited[v] == -1) {
                this.ccCount++
                this.bfs(v, this.ccCount)
            }
        }
    }

    bfs(v, ccId) {
        const queue = []
        queue.push(v)
        // 维护节点所属的连通分量
        this.visited[v] = ccId
        while (queue.length) {
            const curr = queue.shift()

            for (const w of this.g.adj(curr)) {
                if (this.visited[w] == -1) {
                    queue.push(w)
                    // 维护节点所属的连通分量
                    this.visited[w] = ccId
                }
            }
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