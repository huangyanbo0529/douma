

export class TwoVertexPath {
    constructor(g, source, target) {
        this.g = g
        this.source = source
        this.target = target
        this.visited = new Array(g.getV()).fill(false)
        // 存储每个顶点的前一个顶点，初始化为 -1
        this.prevs = new Array(g.getV()).fill(-1)

        this.res = []

        // 深度优先遍历，这里只需要从指定的源顶点遍历就可以
        // 源顶点的前一个顶点设置为源顶点本身
        this.dfs(source, source)

        // 计算一次路径
        this.path()
    }

    // 递归遍历顶点 v，并且维护顶点 v 的前一个顶点的信息
    dfs(v, prev) {
        this.visited[v] = true
        // 维护顶点 v 的前一个顶点
        this.prevs[v] = prev
        if (v == this.target) return true
        for (const w of this.g.adj(v)) {
            if (!this.visited[w]) {
                // v 是 w 的前一个顶点
                // 如果已经找到了，不用再去遍历 v 的下一个相邻节点了
                if (this.dfs(w, v)) return true
            }
        }
        return false
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
        // 1. 如果源顶点到不了目标顶点，直接返回
        if (!this.isConnected()) {
            return this.res
        }

        // 2. 根据 prevs 信息找到路径
        let tmp = this.target
        while (tmp != this.source) {
            this.res.push(tmp)
            tmp = this.prevs[tmp]
        }
        this.res.push(this.source)

        // 3. 翻转
        this.res.reverse()

        return this.res
    }

    getRes() {
        return this.res
    }
}