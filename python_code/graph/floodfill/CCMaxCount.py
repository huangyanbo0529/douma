from graph.AdjSet import AdjSet


class CCMaxCount:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        # self.visited 用于防止一个节点被重复访问
        self.maxVertexNum, self.visited = 0, [False] * self.g.getV()
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if not self.visited[v]:
                self.maxVertexNum = max(self.dfs(v), self.maxVertexNum)

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v) -> int:
        self.visited[v] = True
        res = 1
        for w in self.g.adj(v):
            if not self.visited[w]:
                res += self.dfs(w)
        return res

    def getMaxVertexNum(self):
        return self.maxVertexNum


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt")
    graphDFS = CCMaxCount(adjSet)
    print(graphDFS.getMaxVertexNum())
