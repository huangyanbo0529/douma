

export class TopologySortBFS {

    constructor(g) {
        if (!g.getIsDirected()) {
            throw new Error("只能对有向图进行拓扑排序")
        }
        this.g = g
        this.hasCycle = false

        const indegrees = new Array(g.getV()).fill(0)
        for (let v = 0; v < g.getV(); v++) {
            indegrees[v] = g.indegree(v)
        }

        const queue = []
        for (let v = 0; v < g.getV(); v++) {
            if (indegrees[v] == 0) {
                queue.push(v)
            }
        }

        this.res = new Array(g.getV()).fill(0)
        let index = 0
        while (queue.length) {
            const v = queue.shift()
            this.res[index++] = v
            for (const w of g.adj(v)) {
                indegrees[w]--
                if (indegrees[w] == 0) {
                    queue.push(w)
                }
            }
        }
        if (index != g.getV()) {
            this.hasCycle = true
        }
    }

    isHasCycle() {
        return this.hasCycle
    }

    getRes() {
        return this.res
    }
}