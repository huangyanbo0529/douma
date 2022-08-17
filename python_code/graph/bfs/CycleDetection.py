from collections import deque

from graph.AdjSet import AdjSet


class CycleDetection:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        self.prevs = [-1] * self.g.getV()
        self.hasCycle = False
        self.visited = [False] * self.g.getV()
        for v in range(self.g.getV()):
            if not self.visited[v]:
                if self.bfs(v):
                    self.hasCycle = True
                    break

    def bfs(self, v) -> bool:
        if self.g is None:
            return False
        queue = deque()
        queue.append(v)
        self.visited[v] = True
        # 维护顶点的前一个顶点
        self.prevs[v] = v
        while len(queue):
            curr = queue.popleft()
            for w in self.g.adj(curr):
                if not self.visited[w]:
                    queue.append(w)
                    self.visited[w] = True
                    # 维护顶点的前一个顶点
                    self.prevs[w] = curr
                else:
                    """
                        到了这里，说明：当前的节点 curr 的相邻顶点 w 已经被访问了
                        bug 修复：如果 curr 的相邻顶点 w 又不是当前顶点的前一个顶点的话，说明有环
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
                    """
                    if w != self.prevs[curr]:
                        return True
        return False

    def hasCycleInGraph(self):
        return self.hasCycle


if __name__ == '__main__':
    g = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    graphBFS = CycleDetection(g)
    print(graphBFS.hasCycleInGraph())
