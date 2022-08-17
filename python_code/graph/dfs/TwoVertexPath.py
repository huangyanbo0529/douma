from graph.AdjSet import AdjSet


# 图的两个顶点的路径
class TwoVertexPath:
    def __init__(self, g: AdjSet, source: int, target: int):
        if g is None:
            return
        self.g = g
        self.source = source
        self.target = target
        self.res = []
        # self.visited 用于防止一个节点被重复访问
        self.visited = [False] * self.g.getV()
        # self.prevs 存储每个顶点的前一个顶点，初始化为 -1
        self.prevs = [-1] * self.g.getV()
        # 深度优先遍历，这里只需要从指定的源顶点遍历就可以
        # 源顶点的前一个顶点设置为源顶点本身
        self.dfs(self.source, self.source)

    # 递归遍历顶点 v，并且维护顶点 v 的前一个顶点的信息
    def dfs(self, v, prev) -> bool:
        self.visited[v] = True
        # 维护顶点 v 的前一个顶点
        self.prevs[v] = prev
        if v == self.target:
            return True
        for w in self.g.adj(v):
            if not self.visited[w]:
                # v 是 w 的前一个顶点
                # 如果已经找到了，不用再去遍历 v 的下一个相邻节点了
                if self.dfs(w, v):
                    return True
        return False

    def isConnected(self):
        self.validateVertex(self.target)
        return self.visited[self.target]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))

    def path(self):
        res = []
        # 1. 如果源顶点到不了目标顶点，直接返回
        if not self.isConnected():
            return res

        # 2. 根据 prevs 信息找到路径
        tmp = self.target
        while tmp != self.source:
            res.append(tmp)
            tmp = self.prevs[tmp]
        res.append(self.source)

        # 3. 翻转
        res.reverse()

        return res


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    graphDFS = TwoVertexPath(adjSet, 0, 6)
    print(graphDFS.path())
