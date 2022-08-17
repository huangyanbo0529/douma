

export class Prim {
    constructor(g, cc) {
        this.g = g
        this.res = []

        // g 必须是连通图，否则没有最小生成树
        if (cc.getCCCount() > 1) return

        const MAX_INT = Math.pow(2, 31) - 1

        // Prim
        const visited = new Array(g.getV()).fill(false)
        // 选择顶点 0 作为切分的一部分
        visited[0] = true

        // 进行 v - 1 次切分，每次切分得到最短的横切边
        for (let i = 0; i < g.getV() - 1; i++) {
            let minEdge = [-1, -1, MAX_INT]
            for (let v = 0; v < g.getV(); v++) {
                if (visited[v]) {
                    for (const w of g.adj(v)) {
                        // v-w 横切边
                        // 找到最小的横切边
                        if (!visited[w] && g.getWeight(v, w) < minEdge[2]) {
                            minEdge = [v, w, g.getWeight(v, w)]
                        }
                    }
                }
            }
            this.res.push(minEdge)

            // 扩展切分
            const v = minEdge[0]
            const w = minEdge[1]
            const newV = visited[v] ? w : v
            visited[newV] = true
        }
    }

    getResult() {
        return this.res
    }
}