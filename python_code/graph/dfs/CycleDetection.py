from graph.AdjSet import AdjSet


class CycleDetection:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        # self.visited 用于防止一个节点被重复访问
        self.hasCycle, self.visited = False, [False] * self.g.getV()
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if not self.visited[v]:
                self.dfs(v, v)

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v, prev):
        self.visited[v] = True
        for w in self.g.adj(v):
            if not self.visited[w]:
                self.dfs(w, v)
            else:
                # 否则，w 顶点已经被访问
                # 如果 w 不是 v 的前一个节点的话，那么就存在环
                if w != prev:
                    self.hasCycle = True

    def hasCycleInGraph(self):
        return self.hasCycle


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt")
    graphDFS = CycleDetection(adjSet)
    print(graphDFS.hasCycleInGraph())
