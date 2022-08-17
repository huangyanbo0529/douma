
export class Prim1 {
    constructor(g, cc, minHeap) {
        this.g = g
        this.res = []

        // g 必须是连通图，否则没有最小生成树
        if (cc.getCCCount() > 1) return

        // Prim
        const visited = new Array(g.getV()).fill(false)
        // 选择顶点 0 作为切分的一部分
        visited[0] = true

        for (const w of g.adj(0)) {
            minHeap.add([0, w, g.getWeight(0, w)])
        }

        while (!minHeap.isEmpty()) {

            // 1. 拿到最小横切边
            const minEdge = minHeap.remove()
            if (visited[minEdge[0]] && visited[minEdge[1]]) {
                // 不是横切边
                continue
            }

            //alert(`test1 - ${minEdge}`)

            // 2. 加入到最小生成树中
            this.res.push(minEdge)

            // 3. 扩展切分
            const newV = visited[minEdge[0]] ? minEdge[1] : minEdge[0]
            visited[newV] = true
            // 将新的横切边放入到优先队列
            for (const w of g.adj(newV)) {
                if (!visited[w]) {
                    minHeap.add([newV, w, g.getWeight(newV, w)])
                }
            }
        }
    }

    getResult() {
        return this.res
    }
}