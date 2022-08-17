

// 支持无向无权图和有向无权图
// 空间复杂度：O(V + E)
export class GraphImpl {
    // lines 表示图的信息，从外面传进来
    constructor(lines, isDirected) {
        this.isDirected = isDirected

        let arr = lines[0]
        this.V = parseInt(arr[0])
        this.W = parseInt(arr[1])

        this.adjSet = new Array(this.V).fill(0)
        for (let i = 0; i < this.V; i++) {
            this.adjSet[i] = new Set()
        }

        this.indegrees = new Array(this.V).fill(0)
        this.outdegrees = new Array(this.V).fill(0)

        for (let i = 1; i < lines.length; i++) {
            arr = lines[i]
            const a = parseInt(arr[0])
            this.validateVertex(a)
            const b = parseInt(arr[1])
            this.validateVertex(b)

            // 检测自环边
            if (a == b) {
                throw new Error("出现了自环边，错误")
            }
            // 检测平行边
            if (this.adjSet[a][b] == 1) {
                throw new Error("出现了平行边，错误")
            }

            this.adjSet[a].add(b)
            // 如果是有向图的话，统计顶点的出度和入度
            if (isDirected) {
                this.outdegrees[a]++
                this.indegrees[b]++
            }
            if (!isDirected)
                this.adjSet[b].add(a)
        }
    }

    validateVertex(v) {
        if (v < 0 || v >= this.V) {
            throw new Error("顶点 {0} 不合格".format(v))
        }
    }

    getIsDirected() {
        return this.isDirected
    }

    getV() {
        return this.V
    }

    getW() {
        return this.W
    }

    // 判断两个指定的顶点之间是否有边
    // 时间复杂度：O(1)
    hasEdge(v, w) {
        this.validateVertex(v)
        this.validateVertex(w)

        return this.adjSet[v].has(w)
    }

    // 获取指定顶点所有相邻的顶点
    // 时间复杂度：O(1)
    adj(v) {
        this.validateVertex(v)

        return this.adjSet[v]
    }

    // 获取指定顶点的度数
    degree(v) {
        if (this.isDirected) {
            throw new Error("只有无向图才可以计算顶点的度数")
        }
        return this.adj(v).length
    }

    indegree(v) {
        if (!this.isDirected) {
            throw new Error("只有有向图才可以计算顶点的入度")
        }
        this.validateVertex(v)
        return this.indegrees[v]
    }

    outdegree(v) {
        if (!this.isDirected) {
            throw new Error("只有有向图才可以计算顶点的出度")
        }
        this.validateVertex(v)
        return this.outdegrees[v]
    }

    toString() {
        let res = ""
        res += `顶点数 = ${this.V}，边数 = ${this.W}，isDirected = ${this.isDirected} \n`
        for (let v = 0; v < this.V; v++) {
            res += `${v}: `
            for (const w of this.adjSet[v]) {
                res += `${w} `
            }
            res += "\n"
        }
        return res
    }
}