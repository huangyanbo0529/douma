
// 时间复杂度：O(V * (logV + E))
export class Dijkstra1 {

    constructor(g, source, minHeap) {
        this.g = g

        const MAX_INT = Math.pow(2, 31) - 1

        this.distance = new Array(g.getV()).fill(MAX_INT)
        this.distance[source] = 0
        this.visited = new Array(g.getV()).fill(false)

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
}