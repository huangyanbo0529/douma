

export class CycleDetection {

    constructor(g) {
        this.g = g
        this.visited = new Array(g.getV()).fill(false)
        this.prevs = new Array(g.getV()).fill(-1)
        this.hasCycle = false

        for (let v = 0; v < g.getV(); v++) {
            if (!this.visited[v] && this.bfs(v)) {
                this.hasCycle = true
                break
            }
        }
    }

    bfs(v) {
        const queue = []
        queue.push(v)
        this.visited[v] = true
        // 维护顶点的前一个顶点
        this.prevs[v] = v
        while (queue.length) {
            const curr = queue.shift()

            for (const w of this.g.adj(curr)) {
                if (!this.visited[w]) {
                    queue.push(w)
                    this.visited[w] = true
                    // 维护顶点的前一个顶点
                    this.prevs[w] = curr
                } else {
                    // 到了这里，说明：当前的节点 curr 的相邻顶点 w 已经被访问了
                    // bug 修复：如果 curr 的相邻顶点 w 又不是当前顶点的前一个顶点的话，说明有环
                    /**
                     a----b
                      \  /
                       c
                     假设先访问 a 节点（visited[a] = true），
                     然后 b 和 c 都是 a 的相邻节点，依次将 b 和 c 放入到队列中
                     并且维护 prevs[b] = a 和 prevs[c] = a，且 visited[b] = true 和 visited[c] = true

                     然后从队列中把 b 节点拉出来，进行访问，b 的相邻节点分别是 a 和 c，我们分别来考虑
                     先考虑相邻的节点 a，这个时候：
                     curr = b, w = a，且 visited[w] = true，w = prevs[curr]
                     即相邻的节点已经被访问，并且这个相邻节点是当前节点的前一个节点，不能判断为有环
                     再来考虑相邻的节点 c，这个时候：
                     curr = b, w = c，且 visited[w] = true，w != prevs[curr]
                     即相邻的节点已经被访问，并且这个相邻的节点不是当前节点的前一个节点，此时说明有环

                     其实就是说，在 BFS 的过程中，如果有两条路可以到达同一个节点，那么就说明有环
                     比如节点 c，可以从 a -> c，也可以 a -> b -> c
                     */
                    if (w != this.prevs[curr]) {
                        return true;
                    }
                }
            }
        }
        return false
    }

    getHasCycle() {
        return this.hasCycle
    }
}