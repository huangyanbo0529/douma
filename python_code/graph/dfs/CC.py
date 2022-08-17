from graph.AdjSet import AdjSet


# 求图的连通分量
class CC:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        # self.visited 用于防止一个节点被重复访问
        self.ccCount, self.visited = 0, [False] * self.g.getV()
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if not self.visited[v]:
                self.ccCount += 1
                self.dfs(v)

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v):
        self.visited[v] = True
        for w in self.g.adj(v):
            if not self.visited[w]:
                self.dfs(w)

    def getCcCount(self):
        return self.ccCount


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt")
    cc = CC(adjSet)
    print(cc.getCcCount())
