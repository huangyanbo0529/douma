

export class BipartitionDetection {

    constructor(g) {
        this.g = g
        this.visited = new Array(g.getV()).fill(false)
        // -1 表示没有染颜色
        // 0 红色 1 蓝色
        this.colors = new Array(g.getV()).fill(-1)
        this.isBipartition = true

        for (let v = 0; v < g.getV(); v++) {
            if (!this.visited[v]) this.bfs(v)
        }
    }

    bfs(v) {
        const queue = []
        queue.push(v)
        this.visited[v] = true
        this.colors[v] = 0
        while (queue.length) {
            const curr = queue.shift()

            for (const w of this.g.adj(curr)) {
                // 如果 w 没有遍历过，则需要染色
                if (!this.visited[w]) {
                    queue.push(w)
                    this.visited[w] = true
                    // 给顶点 w 染色，和 curr 的颜色不一样
                    this.colors[w] = 1 - this.colors[curr]
                } else if (this.colors[w] == this.colors[curr]) {
                    // 如果 w 被访问过，并且它的颜色和相邻点一样
                    // 那么可以判定不是二分图
                    return false
                }
            }
        }
        return true
    }

    getIsBipartition() {
        return this.isBipartition
    }
}