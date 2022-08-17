

export class SingleSourcePath1 {

    constructor(g, source, target) {
        this.g = g
        this.visited = new Array(g.getV()).fill(false)
        this.prevs = new Array(g.getV()).fill(-1)
        this.source = source
        this.target = target

        this.bfs(source)
    }

    bfs(v) {
        const queue = []
        queue.push(v)
        this.visited[v] = true
        // 维护顶点的前一个顶点
        this.prevs[v] = v
        while (queue.length) {
            const curr = queue.shift()
            if (curr == this.target) return

            for (const w of this.g.adj(curr)) {
                if (!this.visited[w]) {
                    queue.push(w)
                    this.visited[w] = true
                    // 维护顶点的前一个顶点
                    this.prevs[w] = curr
                }
            }
        }
    }

    isConnected() {
        this.validateVertex(this.target)
        return this.visited[this.target]
    }

    validateVertex(v) {
        if (v < 0 && v >= this.g.getV()) {
            throw new Error("顶点不合法，超出范围")
        }
    }

    path() {
        const res = []
        // 1. 如果源顶点到不了目标顶点，直接返回
        if (!this.isConnected()) {
            return res
        }

        // 2. 根据 prevs 信息找到路径
        let tmp = this.target
        while (tmp != this.source) {
            res.push(tmp)
            tmp = this.prevs[tmp]
        }
        res.push(this.source)

        // 3. 翻转
        res.reverse()

        return res
    }
}