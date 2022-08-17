
export class GraphDFS {
    constructor(g) {
        this.g = g
        if (g == null) return

        this.res = []
        this.visited = new Array(g.getV()).fill(false)

        // 遍历图中每个顶点
        for (let v = 0; v < g.getV(); v++) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!this.visited[v]) this.dfs(v)
        }
    }

    dfs(v) {
        const stack = []
        stack.push(v)

        this.visited[v] = true
        while (stack.length) {
            const curr = stack.pop()
            this.res.push(curr)
            for (const w of this.g.adj(curr)) {
                // 如果已经访问过了，就不压入栈，就不会再次访问了
                if (!this.visited[w]) {
                    stack.push(w)
                    this.visited[w] = true
                }
            }
        }
    }

    getRes() {
        return this.res
    }
}



