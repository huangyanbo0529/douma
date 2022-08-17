
// 时间复杂度：O(V * (logV + E))
export class Dijkstra2 {

    constructor(g, source, minHeap) {
        this.g = g
        this.source = source

        const MAX_INT = Math.pow(2, 31) - 1

        this.distance = new Array(g.getV()).fill(MAX_INT)
        this.distance[source] = 0
        this.visited = new Array(g.getV()).fill(false)

        this.prevs = new Array(g.getV()).fill(-1)

        minHeap.add([source, 0])
        while (!minHeap.isEmpty()) { // O(V)
            // 1. 找到当前没有访问的最短路径节点
            const curr = minHeap.remove()[0] // O(logV)
            if (this.visited[curr]) continue

            // 2. 确认这个节点的最短路径就是当前大小
            this.visited[curr] = true

            // 3. 根据这个节点的最短路径大小，更新其他节点的路径长度
            for (const w of g.adj(curr)) { // O(E)
                if (!this.visited[w]) {
                    if (this.distance[curr] + g.getWeight(curr, w) < this.distance[w]) {
                        this.distance[w] = this.distance[curr] + g.getWeight(curr, w)
                        minHeap.add([w, this.distance[w]])
                        this.prevs[w] = curr
                    }
                }
            }
        }
    }

    minDistanceTo(v) {
        this.validateVertex(v)
        return this.distance[v]
    }

    validateVertex(v) {
        if (v < 0 && v >= this.g.getV()) {
            throw new Error("顶点不合法，超出范围")
        }
    }

    isConnected(v) {
        this.validateVertex(v)
        return this.visited[v]
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
}