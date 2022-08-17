

export class SingleSourcePath {
    constructor(g, source) {
        this.g = g
        this.source = source
        this.visited = new Array(g.getV()).fill(false)
        // 存储每个顶点的前一个顶点，初始化为 -1
        this.prevs = new Array(g.getV()).fill(-1)

        // 深度优先遍历，这里只需要从指定的源顶点遍历就可以
        // 源顶点的前一个顶点设置为源顶点本身
        this.dfs(source, source)
    }

    // 递归遍历顶点 v，并且维护顶点 v 的前一个顶点的信息
    dfs(v, prev) {
        this.visited[v] = true
        // 维护顶点 v 的前一个顶点
        this.prevs[v] = prev
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                // v 是 w 的前一个顶点
                this.dfs(w, v)
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
}