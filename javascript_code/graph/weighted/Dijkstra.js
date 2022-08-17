
// 时间复杂度：O(V * (V + E))
export class Dijkstra {

    constructor(g, source) {
        this.g = g

        const MAX_INT = Math.pow(2, 31) - 1

        this.distance = new Array(g.getV()).fill(MAX_INT)
        this.distance[source] = 0
        this.visited = new Array(g.getV()).fill(false)

        while (true) { // O(V)
            // 1. 找到当前没有访问的最短路径节点
            let curDis = MAX_INT
            let curr = -1
            for (let v = 0; v < g.getV(); v++) { // O(V)
                if (!this.visited[v] && this.distance[v] < curDis) {
                    curDis = this.distance[v]
                    curr = v
                }
            }
            if (curr == -1) break;

            // 2. 确认这个节点的最短路径就是当前大小
            this.visited[curr] = true

            // 3. 根据这个节点的最短路径大小，更新其他节点的路径长度
            for (const w of g.adj(curr)) { // O(E)
                if (!this.visited[w]) {
                    if (this.distance[curr] + g.getWeight(curr, w) < this.distance[w]) {
                        this.distance[w] = this.distance[curr] + g.getWeight(curr, w)
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