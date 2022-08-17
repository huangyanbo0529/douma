

export class GraphBFS {

    constructor(g) {
        this.g = g
        this.visited = new Array(g.getV()).fill(false)
        this.res = []

        for (let v = 0; v < g.getV(); v++) {
            if (!this.visited[v]) this.bfs(v)
        }
    }

    bfs(v) {
        const queue = []
        queue.push(v)
        this.visited[v] = true
        while (queue.length) {
            const curr = queue.shift()
            this.res.push(curr)

            for (const w of this.g.adj(curr)) {
                if (!this.visited[w]) {
                    queue.push(w)
                    this.visited[w] = true
                }
            }
        }
    }

    getRes() {
        return this.res
    }
}