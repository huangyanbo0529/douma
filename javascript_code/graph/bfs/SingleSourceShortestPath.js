

export class SingleSourceShortestPath {

    constructor(g, source) {
        this.g = g
        this.visited = new Array(g.getV()).fill(false)
        this.prevs = new Array(g.getV()).fill(-1)
        this.distance = new Array(g.getV()).fill(-1)
        this.source = source

        this.bfs(source)
    }

    bfs(v) {
        const queue = []
        queue.push(v)
        this.visited[v] = true
        // 维护顶点的前一个顶点
        this.prevs[v] = v
        this.distance[v] = 0
        while (queue.length) {
            const curr = queue.shift()

            for (const w of this.g.adj(curr)) {
                if (!this.visited[w]) {
                    queue.push(w)
                    this.visited[w] = true
                    // 维护顶点的前一个顶点
                    this.prevs[w] = curr
                    // 维护顶点 w 的距离为前一个顶点的距离 +1
                    this.distance[w] = this.distance[curr] + 1
                }
            }
        }
    }

    isConnected(target) {
        this.validateVertex(target)
        return this.visited[target]
    }

    validateVertex(v) {
        if (v < 0 && v >= this.g.getV()) {
            throw new Error("顶点不合法，超出范围")
        }
    }

    path(target) {
        const res = []
        // 1. 如果源顶点到不了目标顶点，直接返回
        if (!this.isConnected(target)) {
            return res
        }

        // 2. 根据 prevs 信息找到路径
        while (target != this.source) {
            res.push(target)
            target = this.prevs[target]
        }
        res.push(this.source)

        // 3. 翻转
        res.reverse()

        return res
    }

    // 返回从 source 到 target 两点之间的距离
    // O(n) -> O(1)
    distanceOf(target) {
        this.validateVertex(target)
        return this.distance[target]
    }
}