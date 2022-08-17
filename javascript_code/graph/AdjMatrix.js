
// 邻接矩阵表达图结构
// 空间复杂度：O(V^2)，浪费空间
export class AdjMatrix {
    // lines 表示图的信息，从外面传进来
    constructor(lines) {
        let arr = lines[0]
        this.V = parseInt(arr[0])
        this.W = parseInt(arr[1])

        this.adjMatrix = new Array(this.V).fill(0).map(() => new Array(this.V).fill(0))
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
            if (this.adjMatrix[a][b] == 1) {
                throw new Error("出现了平行边，错误")
            }

            this.adjMatrix[a][b] = 1
            this.adjMatrix[b][a] = 1
        }
    }

    validateVertex(v) {
        if (v < 0 || v >= this.V) {
            throw new Error("顶点 {0} 不合格".format(v))
        }
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

        return this.adjMatrix[v][w] == 1
    }

    // 获取指定顶点所有相邻的顶点
    // 时间复杂度：O(V)
    adj(v) {
        this.validateVertex(v)

        const res = []
        for (let i = 0; i < this.V; i++) {
            if (this.adjMatrix[v][i] == 1) {
                res.push(i)
            }
        }

        return res
    }

    // 获取指定顶点的度数
    degree(v) {
        return this.adj(v).length
    }

    toString() {
        let res = ""
        res += `顶点数 = ${this.V}，边数 = ${this.W} \n`
        for (let i = 0; i < this.V; i++) {
            for (let j = 0; j < this.V; j++) {
                res += this.adjMatrix[i][j] + " "
            }
            res += "\n"
        }
        return res
    }
}