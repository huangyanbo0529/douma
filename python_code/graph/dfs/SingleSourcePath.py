from graph.AdjSet import AdjSet


# 图的单源路径
class SingleSourcePath:
    def __init__(self, g: AdjSet, source: int):
        if g is None:
            return
        self.g = g
        self.source = source
        # self.visited 用于防止一个节点被重复访问
        self.visited = [False] * self.g.getV()
        # self.prevs 存储每个顶点的前一个顶点，初始化为 -1
        self.prevs = [-1] * self.g.getV()
        # 深度优先遍历，这里只需要从指定的源顶点遍历就可以
        # 源顶点的前一个顶点设置为源顶点本身
        self.dfs(self.source, self.source)

    # 递归遍历顶点 v，并且维护顶点 v 的前一个顶点的信息
    def dfs(self, v, prev):
        self.visited[v] = True
        # 维护顶点 v 的前一个顶点
        self.prevs[v] = prev
        for w in self.g.adj(v):
            if not self.visited[w]:
                # v 是 w 的前一个顶点
                self.dfs(w, v)

    def isConnected(self, target):
        self.validateVertex(target)
        return self.visited[target]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))

    def path(self, target):
        res = []
        # 1. 如果源顶点到不了目标顶点，直接返回
        if not self.isConnected(target):
            return res

        # 2. 根据 prevs 信息找到路径
        while target != self.source:
            res.append(target)
            target = self.prevs[target]
        res.append(self.source)

        # 3. 翻转
        res.reverse()

        return res


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    graphDFS = SingleSourcePath(adjSet, 0)
    print(graphDFS.path(6))
